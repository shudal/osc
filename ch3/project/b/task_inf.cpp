//
// Created by perci on 2020/6/9.
//
#include <iostream>
using namespace std;


int task_inf_init(void) {
  printk(KERN_INFO "loading task_inf module");
  auto i =0;
  return 0;
}

void task_inf_exit(void) {

}

module_init(task_inf_init);
module_exit(task_inf_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Task Information Module");
MODULE_AUTHOR("MJH");
