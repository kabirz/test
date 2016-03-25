/*
 * Author : kabir
 * Email : zhonghuiping@droi.com
 * Last modified : 2015-05-19 21:09
 * Filename : module_sample.c
 * Description : This is init sample code
 */
#include <linux/module.h>
#include <linux/init.h>

int __init mod_init(void)
{
	printk("module init!\n");
	return 0;
}
void __exit mod_exit(void)
{
	printk("module exit!\n");
}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("kabir.zhong");
MODULE_DESCRIPTION("THis is module_sample code");
MODULE_VERSION("v1.0");
MODULE_ALIAS("klist");
