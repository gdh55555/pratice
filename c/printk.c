#include <stdio.h>
#include<linux/kernel.h>
#include<linux/module.h>

int main()
{
    printk(KERN_INFO"Hello,World\n");
    return 0;
}
