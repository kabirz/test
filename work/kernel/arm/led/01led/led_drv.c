/*
 * Author : ZhongHuiping
 * Email : zhonghuiping@tydtech.com
 * Last modified : 2014-02-25 14:46
 * Filename : led_drv.c
 * Description : 
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <asm/io.h>
#include <linux/proc_fs.h>

typedef volatile unsigned int vu32;
#define LED_PHY	0x7F008000
#define LEDCON	0x820
#define LEDDAT	0x824
#define LED_ON	0
#define LED_OFF	1

struct led_st {
	void __iomem *virt;
	vu32 *ledcon;
	u32 *leddat;
	u32 user;
	u32 state;
	int dev_no;
	
	struct cdev dev;
	struct proc_dir_entry *proc;
	struct class *cls;

	void (*open)(struct led_st *led);
	void (*close)(struct led_st *led);
};

void s3c_led_open(struct led_st *led)
{
	*led->leddat &= ~0x1;
	led->user++;
	led->state = LED_ON;
}

void s3c_led_close(struct led_st *led)
{
	*led->leddat |= 0x1;
	led->user--; led->state = LED_OFF; }

int led_st_init(struct led_st *led)
{
	led->virt = ioremap(LED_PHY, SZ_4K);
	if(led->virt == NULL){
		printk("ioremap() error\n");
		goto remap_error;
	}
	led->ledcon = led->virt + LEDCON;
	led->leddat = led->virt + LEDDAT;
	led->user = 0;
	led->state = LED_OFF;

	*led->ledcon &= ~0xf;
	*led->ledcon |= 1;
	*led->leddat |= 1;

	led->open = s3c_led_open;
	led->close = s3c_led_close;

	return 0;

remap_error:
	return -EPERM;
}

void led_st_exit(struct led_st *led)
{
	*led->ledcon &= ~0xf;
	*led->ledcon |= 1;
	*led->leddat |= 1;
	iounmap(led->virt);
}

int led_release(struct inode *no, struct file *fp)
{
	struct led_st *led = container_of(no->i_cdev, struct led_st, dev);
	
	led->close(led);
	
	return 0;
}

int led_open(struct inode *no, struct file *fp)
{
	struct led_st *led = container_of(no->i_cdev, struct led_st, dev);

	led->open(led);

	return 0;
}

struct file_operations led_ops = {
	.owner = THIS_MODULE,
	.open = led_open,
	.release = led_release,
};

int up_led_state(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	struct led_st *led = data;

	if(led->state == LED_ON){
		ret += sprintf(page + ret, "LED:ON\n");
	}else{
		ret += sprintf(page + ret, "LED:OFF\n");
	}
	
	*eof = 1;
	
	return ret;
}

struct led_st led;

static __init int led_init(void)
{
	int ret;

	ret = led_st_init(&led);
	if(ret < 0){
		printk("led_st_init() error\n");
		return -EPERM;
	}

	ret = alloc_chrdev_region(&led.dev_no, 2, 1, "led");
	if(ret < 0){
		printk("alloc_chrdev_region() error\n");
		goto alloc_error;
	}	

	cdev_init(&led.dev, &led_ops);
	ret = cdev_add(&led.dev, led.dev_no, 1);
	if(ret < 0){
		printk("cdev_add() error\n");
		goto add_error;
	}

	printk("MAJOR:%d, MINOR:%d\n", MAJOR(led.dev_no), MINOR(led.dev_no));
	
	led.cls = class_create(THIS_MODULE,"led");
	if(!led.cls)
		goto class_err;

	if(device_create(led.cls,NULL,led.dev_no,NULL,"name")<0)
		goto device_err;

	led.proc = create_proc_read_entry("led", 0, NULL, up_led_state, &led);
	if(led.proc == NULL){
		printk("create_proc_read_entry() error\n");
		goto proc_error;
	}
	
	return 0;
proc_error:
	device_destroy(led.cls,led.dev_no);
device_err:
	class_destroy(led.cls);
class_err:
	cdev_del(&led.dev);
add_error:
	unregister_chrdev_region(led.dev_no, 1);
alloc_error:
	led_st_exit(&led);
	
	return -EPERM;
}

static __exit void led_exit(void)
{
	remove_proc_entry("led", NULL);
	device_destroy(led.cls,led.dev_no);
	class_destroy(led.cls);
	cdev_del(&led.dev);
	unregister_chrdev_region(led.dev_no, 1);
	led_st_exit(&led);
}

module_init(led_init);
module_exit(led_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZhongHuiping");
MODULE_DESCRIPTION("This is 6410 board led code");
MODULE_VERSION("1.0");
