#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Normal McEntire<norman.mcentire@gmail.com>");
MODULE_DESCRIPTION("Hello World Kernel Module");
MODULE_VERSION("0.1");

static int __init hello_init(void) // static hides as it is accessed only in this file and can't be accessed outside
{
	printk(KERN_INFO "Hello kernel Module"); // no comma
	return 0;				 // since it goes into kernel ring buffer we can see this message using dmesg
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye kernel module\n"); // no comma
}

module_init(hello_init); // called when module is loaded
module_exit(hello_exit); // called when module is unloaded
