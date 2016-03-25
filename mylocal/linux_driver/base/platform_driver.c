#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>


int test_probe(struct platform_device *pdev)
{
	pr_warning("test probe init\n");
	return 0;
}
int test_remove(struct platform_device *pdev)
{
	pr_warning("test probe exit\n");
	return 0;
}
struct platform_driver test_driver = {
	.probe  = test_probe,
	.remove = test_remove,
	.driver = {
	.name = "test-platform",
	},
};

module_platform_driver(test_driver);

MODULE_AUTHOR("kabir");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("platform driver");
MODULE_VERSION("v1.0");
