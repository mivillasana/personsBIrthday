#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>


struct birthday {
	int day;
	int month;
	int year;
	char *name;
	struct list_head list;
};

struct birthday *person;
struct list_head *pos;

static LIST_HEAD(birthday_list);
/* This function is called when the module is loaded. */
int init_persons(void)
{
	int day, month, year;
	char *name;
	person = kmalloc(sizeof(*person),GFP_KERNEL);
	person->day = 2;
	person->month = 8;
	person->year = 1995;
	person->name = "test"

	INIT_LIST_HEAD(&person->list);
	printk(KERN_INFO "Loading Person 1\n");

	while(i<5)
	{

		ptr = kmalloc(sizeof(*ptr),GFP_KERNEL);
		get_random_bytes(&day, 1);
	    ptr->day = day % 31;
	    if(ptr->day < 0)
	        ptr->day = ptr->day * -1;

	    get_random_bytes(&month, 1);
	    ptr->month = month % 12;

	    if(ptr->month < 0)
	        ptr->month = ptr->month * -1;

	    get_random_bytes(&year, 1);
	    ptr->year = (year % 2000)+1900;

	    if(ptr->year < 0)
	        ptr->year = ptr->year * -1;

	    list_add(&(ptr->list), &person->list);
    }
	
	printk(KERN_INFO "Traversing the list:)\n");
    list_for_each(pos, &person->list){
        tmp = list_entry(pos, struct birthday, list);
        printk("day = %d month = %d year = %d\n", tmp->day, tmp->month, tmp->year);
    }

    return 0;
}

/* This function is called when the module is removed. */
void delete_persons(void) {
	delete *person;
	printk(KERN_INFO "Deleting Person\n");
}


list_add_tail(&person->list, &birthday_list);
/* Macros for registering module creating and deleting persons. */
module_init( init_persons );
module_exit( delete_persons );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
