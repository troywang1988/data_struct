#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

struct node_st
{
	struct score_st data;
	struct node_st *next;
};

int list_insert(struct node_st **list,struct score_st *data)
{
	struct node_st *newnode;

	newnode = malloc(sizeof(*newnode));
	if(newnode == NULL)
		return -1;

	newnode->data = *data;
	newnode->next = *list;
	*list = newnode;

	return 0;
}

struct score_st *list_find(struct node_st *list,int id)
{
	struct node_st *p = list;
	
	for(;p != NULL ; p = p->next)
		if(p->data.id == id)
			return &p->data;	
	return NULL;
}
void print_s(struct score_st *p)
{
	printf("%d %s %d\n",p->id,p->name,p->math);
}

void list_display(struct node_st *list)
{
	struct node_st *p = list;
	
	for(;p != NULL ; p = p->next)
		print_s(&p->data);
	
}

int main()
{
	int i;
	struct score_st tmp,*datap;
	struct node_st *list = NULL;

	for(i = 0 ;i < 6; i++)
	{
		tmp.id = i;
		tmp.math = 100-i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);

		list_insert(&list ,&tmp);
	}	

	list_display(list);

	datap = list_find(list,20);
	if(datap == NULL)
		printf("can not find!\n");
	else
		print_s(datap);

	return 0;
}







