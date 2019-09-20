#include <stdio.h>

#include "llist.h"

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

static void print_s(void *record)//print_s函数的型参是void *record
{
	struct score_st *data = record;

	printf("%d %s %d\n",data->id,data->name,data->math);
}

int main()
{
	struct score_st tmp;
	LLIST *handle;//typedef struct LLIST
	int i;

	handle = llist_create(sizeof(struct score_st));
	if(handle == NULL)
		return -1;

	for(i = 0 ;i < 6 ; i++)
	{
		tmp.id = i;
		tmp.math = 100-i;
		snprintf(tmp.name,NAMESIZE,"std%d",i);//snprintf

		llist_insert(handle,&tmp,LLIST_BACKWARD);
	}
	
	llist_travel(handle,print_s);

	llist_destroy(handle);
	return 0;
}





