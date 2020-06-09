//
// Created by perci on 2020/6/9.
//

#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/printk.h>
#include <linux/module.h>
#include <linux/uaccess.h>


#define OUTPUT_BUFFER_SIZE 128
#define PROC_NAME "taskinf"

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static struct file_operations proc_ops = {
    .owner = THIS_MODULE,
    .read = proc_read
};

int task_inf_init(void) {
  printk(KERN_INFO "loading task_inf module");
  proc_create(PROC_NAME, 0, NULL, &proc_ops);
  return 0;
}

void task_inf_exit(void) {
  remove_proc_entry(PROC_NAME, NULL);
  printk(KERN_INFO "task_inf module removed");
}
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
char buffer[OUTPUT_BUFFER_SIZE];
int rv = sprintf(buffer, "hi");

copy_to_user(usr_buf, buffer, rv);
return rv;
}
module_init(task_inf_init);
module_exit(task_inf_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Task Information Module");
MODULE_AUTHOR("MJH");
