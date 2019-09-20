#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	struct list_head node;		
	int math;
};

static void print_s(const void *data)
{
	const struct score_st *d = data;
	printf("%d %s %d\n",d->id,d->name,d->math);
}


int main()
{
	int i;
	struct score_st *tmp;
	struct list_head *cur;

	LIST_HEAD(head);

	for(i = 0 ;i < 6 ; i++)
	{
		tmp = malloc(sizeof(*tmp));
		/*if error*/
		tmp->id = i;
		tmp->math = 100-i;
		snprintf(tmp->name,NAMESIZE,"stu%d",i);
		
		list_add(&tmp->node , &head);

	}

	__list_for_each(cur,&head)
	{
		tmp = list_entry(cur,struct score_st ,node );
		print_s(tmp);
	}





	return 0;
}





