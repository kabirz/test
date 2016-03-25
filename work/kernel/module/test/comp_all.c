#include <linux/module.h>
#include <linux/init.h>

#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/completion.h>

MODULE_LICENSE("Dual BSD/GPL");

#undef KERN_DEBUG
#define KERN_DEBUG "<1>"

static int complete_major=250;
static int reader_count = 0;

DECLARE_COMPLETION(comp);

ssize_t complete_read(struct file *filp,char __user *buf,size_t count,loff_t *pos)
{
	printk(KERN_DEBUG "process %i (%s) going to sleep,waiting for writer/n",current->pid,current->comm);
	reader_count++;
	printk(KERN_DEBUG "In read ,before comletion: reader count = %d /n",reader_count);
	wait_for_completion(&comp);
	reader_count--;
	printk(KERN_DEBUG "awoken %s (%i) /n",current->comm,current->pid);
	printk(KERN_DEBUG "In read,after completion : reader count = %d /n",reader_count);
	if(reader_count == 0)
		INIT_COMPLETION(comp);

	return 0;
}

ssize_t complete_write(struct file *filp,const char __user *buf,size_t count,loff_t *pos)
{
	printk(KERN_DEBUG "process %i (%s) awoking the readers.../n",current->pid,current->comm);
	printk(KERN_DEBUG "In write ,before do complete_all : reader count = %d /n",reader_count);

	if(reader_count != 0)  
		complete_all(&comp);

	printk(KERN_DEBUG "In write ,after do complete_all : reader count = %d /n",reader_count);

	return count;
}

struct file_operations complete_fops={
	.owner = THIS_MODULE,
	.read = complete_read,
	.write = complete_write,
};

int complete_init(void)
{
	int result;

	result=register_chrdev(complete_major,"complete",&complete_fops);
	if(result<0)
		return result;
	if(complete_major==0)
		complete_major =result;

	printk(KERN_DEBUG    "complete driver test init! complete_major=%d/n",complete_major);
	printk(KERN_DEBUG "¾²Ì¬³õÊ¼»¯completion/n");

	return 0;
}

void complete_exit(void)
{
	unregister_chrdev(complete_major,"complete");
	printk(KERN_DEBUG    "complete driver    is removed/n");
}

module_init(complete_init);
module_exit(complete_exit);
