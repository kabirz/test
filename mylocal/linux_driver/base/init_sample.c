/*
 * Author : kabir
 * Email : zhonghuiping@droi.com
 * Last modified : 2015-05-19 20:57
 * Filename : init_sample.c
 * Description :  This is init sample code
 */
#include <linux/module.h>
#include <linux/init.h>

int __init init_module(void)
{
	printk("module init!\n");
	return 0;
}
void __exit cleanup_module(void)
{
	printk("module exit!\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kabir.zhong");
MODULE_DESCRIPTION("THis is init_sample code");
MODULE_VERSION("v1.0");
MODULE_ALIAS("klist");
