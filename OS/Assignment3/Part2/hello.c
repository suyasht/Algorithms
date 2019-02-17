#include <linu x/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>

MODULE_LICENSE("DUAL BSD/GPL");

#define DEVICE_NAME "numpipe"

static DEFINE_SEMAPHORE(sem1);
static DEFINE_SEMAPHORE(sem2);
static DEFINE_MUTEX(mut);

typedef struct fifo_queue{
	char ** size;
	int start,end;	
}Queue;

int open_numpipe (struct inode *pinode, struct file *pfile );
{
	printk(KERN_ALERT "In %s function!\n", __FUNCTION__);
	return 0;

}


ssize_t read_numpipe (struct file *pfile, char __user *buffer, size_t length, loff_t *offset);
{
	printk(KERN_ALERT "In %s function!\n", __FUNCTION__);
	return 0;

}


ssize_t write_numpipe (struct file *pfile , const char __user *buffer, size_t length, loff_t *offset);
{
	printk(KERN_ALERT "In %s function!\n", __FUNCTION__);
	return length;

}

int close_numpipe (struct inode *pinode, struct file *pfile);
{
	printk(KERN_ALERT "In %s function!\n", __FUNCTION__);
	return 0;
}



	static struct file_operations linepipe_fileops = {		
	.open = open_numpipe,
	.read = read_numpipe,
	.write = write_numpipe,
	.release = close_numpipe
};

// called when module is installed
int __init init_pipe()
{
	printk(KERN_ALERT "Pipe Added\n");
	if(misc_register(&numpipe_fileops))
	{
		printk(KERN_ALERT "Pipe Added\n");
	}
	else 
	{
		printk(KERN_ALERT "Pipe Add failed\n");
	}


	sema_init(&empty, N);
	sema_init(&full, 0);
	mutex_init(&mut); 

	return 0;
}



// called when module is removed
void __exit cleanup_module()
{
	printk(KERN_ALERT "mymodule: Goodbye, cruel world!!\n");
}

