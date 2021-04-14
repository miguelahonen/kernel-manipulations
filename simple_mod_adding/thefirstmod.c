#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "thefirstmod"

static int dev_open(struct inode*, struct file*);
static int dev_release(struct inode*, struct file*);
static ssize_t dev_read(struct file*, char*, size_t, loff_t*);
static ssize_t dev_write(struct file*, const char*, size_t, loff_t*);

static struct file_operations fops = {
	.open = dev_open,
	.read = dev_read,
	.write = dev_write,
	.release = dev_release,
};

static int major;

static int __init thefirstmod_init(void) {
	major = register_chrdev(0, DEVICE_NAME, &fops);
	if (major < 0) {
		printk(KERN_ALERT "Thefirstmod load failed\n");
		return major;
	}

	printk(KERN_INFO "The first module has been loaded%d\n", major);
	return 0;

}

static void __exit thefirstmod_exit(void) {
	unregister_chrdev(major, DEVICE_NAME);
	printk(KERN_INFO "The first module has been unloaded\n");
}
static int dev_open(struct inode *inodep, struct file *filep) {
	printk(KERN_INFO "TheFirstMod Device opened\n");
	return 0;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
	printk(KERN_INFO "TheFirstMod is read only\n");
	return -EFAULT;
}

static int dev_release(struct inode *inodep, struct file *filep) {
	printk(KERN_INFO "TheFirstMod Device closed\n");
	return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
	int errors = 0;
	char *message = "The egg opened around thirty years ago - kwaak!\n";
	int message_len = strlen(message);

	errors = copy_to_user(buffer, message, message_len);

	return errors == 0 ? message_len : -EFAULT;
}


module_init(thefirstmod_init);
module_exit(thefirstmod_exit);

