#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x57a42d88, "module_layout" },
	{ 0x8888fdc7, "cdev_del" },
	{ 0x193eaea8, "cdev_init" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x38f42821, "down_interruptible" },
	{ 0xb5b6bed6, "remove_proc_entry" },
	{ 0xdcefeadd, "device_destroy" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x91715312, "sprintf" },
	{ 0x5f754e5a, "memset" },
	{ 0x74c97f9c, "_raw_spin_unlock_irqrestore" },
	{ 0x2f7962a1, "down_trylock" },
	{ 0x27e1a049, "printk" },
	{ 0xfb2dff80, "device_create" },
	{ 0xb39b257, "cdev_add" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x8e2e7ff8, "create_proc_entry" },
	{ 0xbd7083bc, "_raw_spin_lock_irqsave" },
	{ 0x2eb22412, "up" },
	{ 0x27d66eb3, "class_destroy" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x9cadc595, "__class_create" },
	{ 0x3c3e55e, "wmt_getsyspara" },
	{ 0x635b340, "down_timeout" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

