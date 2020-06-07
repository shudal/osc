/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/hash.h>
#include <linux/kernel.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);
	printk(KERN_INFO "hz=%lu", HZ);
	printk(KERN_INFO "jiffies=%lu\n", jiffies);
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	int x=0;
	int i=2;
	for (i=2; i<=24; i++) {
		if (24 % i == 0  && 3300 % i == 0) {
			x = i;	
		}
	}
	printk(KERN_INFO "x=%d\n", x);
	printk(KERN_INFO "jiffies=%lu\n", jiffies);
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

