#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/cdev.h>
#include <linux/miscdevice.h>
#define TAG "[led test]:"

static struct input_dev* test_led_dev;

static void led_on(void)
{
	printk(TAG"led on\n");
}

static void led_off(void)
{
	printk(TAG"led off\n");
}

static int test_led_event(struct input_dev *dev, unsigned int type, unsigned int code, int value)
{
	printk(TAG"test_led_event\n");
	if (type != EV_LED)return -1;

	switch(value)
	{
		case 0:
			led_off();
			break;
		case 1:
			led_on();
			break;
	}
	return 0;
}

static int __init test_led_init(void)
{
	test_led_dev=input_allocate_device();
	test_led_dev->evbit[0] = BIT(EV_LED);
	test_led_dev->ledbit[0] = BIT(LED_NUML);
	test_led_dev->event = test_led_event;

	test_led_dev->name = "test_led";
	test_led_dev->phys = "test_LED_phys";
	test_led_dev->id.bustype = BUS_HOST;
	test_led_dev->id.vendor = 0x001f;
	test_led_dev->id.product = 0x0001;
	test_led_dev->id.version = 0x0100;

	input_register_device(test_led_dev);
	printk(TAG"%s\n", "test_led init");
	return 0;
}

static void __exit test_led_exit(void)
{
	input_unregister_device(test_led_dev);
}

module_init(test_led_init);
module_exit(test_led_exit);
MODULE_AUTHOR("kabir.zhong");
MODULE_DESCRIPTION("test led driver");
MODULE_LICENSE("GPL");

