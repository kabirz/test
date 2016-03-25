#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
struct platform_device *test_device;

int __init device_init(void)
{
	test_device = platform_device_register_simple("test-platform", -1, NULL, 0);
	if (test_device < 0)
		return -ENODEV;
	return 0;
}

void __exit device_exit(void)
{
	platform_device_unregister(test_device);
}
module_init(device_init);
module_exit(device_exit);

MODULE_AUTHOR("kabir");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("platform device");
MODULE_VERSION("v1.0");
