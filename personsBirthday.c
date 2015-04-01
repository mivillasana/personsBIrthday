#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/String.h>


struct birthday {
	int day;
	int month;
	int year;
	String name;
	struct list_head list;
};

void main (void)
{
static LIST_HEAD(birthday_list);
struct birthday *person;

person = kmalloc(sizeof(*person),GFP_KERNEL);
person->day = 2;
person->month = 8;
person->year = 1995;
person->name ="name"

INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday_list);

}

void remove()
{

	//testing
}

void display ()
{}
