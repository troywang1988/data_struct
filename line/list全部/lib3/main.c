#include <stdio.h>
#include <string.h>

#include "llist.h"

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

static void print_s(void *record)
{
	struct score_st *data = record;

	printf("%d %s %d\n",data->id,data->name,data->math);
}

static int id_cmp(const void *key,const void *data)
{
	const int *k = key;
	const struct score_st *d = data;

	return (*k - d->id);

}
static int name_cmp(const void *key,const void *data)
{
	const char *k = key;
	const struct score_st *d = data;
	
	return (strcmp(k,d->name));
}

int main()
{
	struct score_st tmp,*datap;
	LLIST *handle;
	int i,id = 3,ret;
	char *name = "stu40";

	handle = llist_create(sizeof(struct score_st));
	if(handle == NULL)
		return -1;

	for(i = 0 ;i < 6 ; i++)
	{
		tmp.id = i;
		tmp.math = 100-i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);

		handle->insert(handle,&tmp,LLIST_BACKWARD);
	}
	
	handle->travel(handle,print_s);

	printf("\n\n");
#if 0 
//	datap = llist_find(handle,&id,id_cmp);
	datap = llist_find(handle,name,name_cmp);
	if(datap == NULL)
		printf("can not find!\n");
	else
		print_s(datap);

	llist_delete(handle,&id,id_cmp);
	llist_travel(handle,print_s);
	
#endif
	ret = handle->fetch(handle,&id,id_cmp,&tmp);
	handle->travel(handle,print_s);
	printf("\n\n");
	if(ret == 0)
		print_s(&tmp);



	llist_destroy(handle);
	return 0;
}





