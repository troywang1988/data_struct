#include <stdio.h>
#include <string.h>

#include "stack.h"

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

int main()
{
	STACK *handle;
	struct score_st tmp,*datap;
	int i,id = 3,ret;
	char *name = "stu40";

	handle = stack_create(sizeof(struct score_st));
	if(handle == NULL)
		return -1;

	for(i = 0 ;i < 6 ; i++)
	{
		tmp.id = i;
		tmp.math = 100-i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);

		stack_push(handle,&tmp);
	}
	
	while(1)
	{
		ret = stack_pop(handle,&tmp);
		if(ret != 0)  //stack_pop函数调用llist_fetch函数，如果fetch成功，返回值是0，即ret＝0
			break;
		print_s(&tmp);  //打印删除后
	}

	stack_destroy(handle);
	return 0;
}





