/*
*  hello−1.c − The simplest kernel module. 
* https://www.tldp.org/LDP/lkmpg/2.6/lkmpg.pdf
*/
#include <linux/module.h>
/* Needed by all modules */
#include <linux/kernel.h>
/* Needed for KERN_INFO */

int init_module(void){
    printk(KERN_INFO "The info.\n");
    /*
    * A non 0 return means init_module failed; module can't be loaded.
    * 
    */
    return 0;
}
void cleanup_module(void){
    printk(KERN_INFO "The info ends.\n");
}
