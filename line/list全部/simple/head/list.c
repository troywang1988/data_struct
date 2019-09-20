#include<stdio.h>
#include<stdio.h>

#include"list.h"


linklist *linklist_creat()
{
	linklist *L;

	L = malloc(sizeof(*L));
	if(L == NULL)
		return NULL;
	L->next = NULL;
	return L;
}

int linklist_insert(linklist *L,int i,datatype *x)
{
	int j = 0;
	linklist *p = L,*q;

	while(p && j < i)
	{
		p = p->next;
		j++;
	}
		
	if(p != NULL)
	{
		q = malloc(sizeof(*q));
		if(q == NULL)
		return -1;
	q->data = *x;
	q->next = NULL;
	q->next = p->next;
	p->next = q;

	return 0;
	}
	else
		if(p == NULL)
			return -1;
		else
			return -2;
}

int linklist_order_insert(linklist *L,datatype *x)
{
	linklist *p = L,*q;

	while(p->next && p->next->data < *x)
		p = p->next;

	q = malloc(sizeof(*q));
	if(q == NULL)
	 return -1;
	q->data = *x;
	q->next = NULL;

	q->next = p->next;
	p->next = q;
	return 0;
}

int linklist_delete(linklist *L,datatype*x)
{
	linklist *p = L,*q;
	
	while(p)
	{
	if(p->next->data == *x)
	{	
		q = malloc(sizeof(*q));
		if(q == NULL)
			return -1;
		
		q = p->next;
		p->next = q->next;
		return q;
		free (q);
		q == NULL;
	}	
		p = p->next;
	}
	return 0;
}

int linklist_delete_at(linklist *L,int i,datatype *x)
{
	int j = 0;
	linklist *p = L,*q;
	
	while(p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if(p != NULL)
	{
		q = malloc(sizeof(*q));
		if(q = NULL)
			return -1;
		q = p->next;
		p->next = q->next;
		*x = q->data;//将data装进*x，返回
		free(q);
		q = NULL;
		return *x;
	}
		else if(q == NULL)
				return -1;
			else return -2;
}

void linklist_display(linklist *L)
{
	linklist *p = L,*q;
	
	while(p)
	{
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

void linklist_destroy(linklist *L)
{
	linklist *p = L,*q;
	
	while(p)
	{
		q = p->next;//保存p->next
		printf("destroy:%d\n",p->data);
		free(p);
		p = NULL;
		p = q;
	}
}

void linklist_reverse(linklist *L)
{
	linklist *p = L;*q,*head;
	while(p->next != NULL)
	{
		q = malloc(sizeof(*q));
		if(q == NULL )
			return NULL;
		
		q = p->next;
		p->next = q->next;
		q->next = head;
		head == q;
		
		free(q);
		q == NULL;
		
		p = p->next;
	}
}
