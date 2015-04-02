#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/string.h>


struct birthday {
	int day;
	int month;
	int year;
	string name;
	struct list_head list;
};
static LIST_HEAD(birthday_list);
/* This function is called when the module is loaded. */
int init_persons(void)
{
    printk(KERN_INFO "Loading Person 1\n");
	struct birthday *person;

	person = kmalloc(sizeof(*person),GFP_KERNEL);
	person->day = 2;
	person->month = 8;
	person->year = 1995;
	person->name = "test"

    return 0;
}

/* This function is called when the module is removed. */
void delete_persons(void) {
	delete *person;
	printk(KERN_INFO "Deleting Person\n");
}

/* Macros for registering module initilalize and tail pointers. */
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);
/* Macros for registering module creating and deleting persons. */
module_init( init_persons );
module_exit( delete_persons );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
