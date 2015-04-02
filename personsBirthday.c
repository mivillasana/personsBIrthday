#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/random.h>

struct birthday {
	int day;
	int month;
	int year;
	char *name;
	struct list_head list;
};

struct birthday *person, *tmp, *ptr;
struct list_head *pos;

/* This function is called when the module is loaded. */
int person_init(void)
{
	int day, month, year;
	int i = 0;
	char *name;
	person = kmalloc(sizeof(*person),GFP_KERNEL);
	person->day = 2;
	person->month = 8;
	person->year = 1995;
	person->name = "test";

	INIT_LIST_HEAD(&person->list);
	printk(KERN_INFO "Loading Persons:\n");

	while(i<5)
	{

		ptr = kmalloc(sizeof(*ptr),GFP_KERNEL);
		ptr->name = "person "+i;
		get_random_bytes(&day, 1);
	    ptr->day = day % 31;
	    if(ptr->day < 0)
	        ptr->day = ptr->day * -1;

	    get_random_bytes(&month, 1);
	    ptr->month = month % 12;

	    if(ptr->month < 0)
	        ptr->month = ptr->month * -1;

	    get_random_bytes(&year, 1);
	    ptr->year = (year % 99);

	    if(ptr->year < 0)
	        ptr->year = ptr->year * -1;

	    list_add(&(ptr->list), &person->list);
	    i = i +1;
    }
	
	printk(KERN_INFO "Beginning to traverse the list:\n");
    list_for_each(pos, &person->list){
        tmp = list_entry(pos, struct birthday, list);
        printk("%s birthday is %d/%d/%d\n",tmp->name, tmp->month, tmp->day, tmp->year);
    }

    return 0;
}

/* This function is called when the module is removed. */
void delete_persons(void) 
{
	list_for_each_entry(ptr, tmp, &person->list,list)
	{
		list_del(&ptr->list);
		kfree(ptr);
	}
	printk(KERN_INFO "Deleting Persons!\n");
}

/* Macros for registering module creating and deleting persons. */
module_init( person_init );
module_exit( delete_persons );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
