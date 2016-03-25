/*
 * Author : kabir
 * Email : zhonghuiping@droi.com
 * Last modified : 2015-05-19 21:09
 * Filename : rand.c
 * Description : This is init sample code
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/random.h>

int __init mod_init(void)
{
	int i;
	printk("module init!\n");
	for(i = 1; i < 8; i++) 
		printk("ramd=%d\n",get_random_int()%100);
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
MODULE_ALIAS("rand");
