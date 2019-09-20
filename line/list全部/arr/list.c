#include <stdio.h>
#include <stdlib.h>

#include "list.h"


sqlist *sqlist_create(void)
{
	sqlist *L;

	L = malloc(sizeof(*L));
	if(L == NULL)
		return NULL;
	
	L->last = -1;

	return L;
}

void sqlist_create1(sqlist **L)
{
	*L = malloc(sizeof(**L));
	if(*L == NULL)
		return ;
	(*L)->last = -1;
}

int sqlist_insert(sqlist *L,int i,datatype *x)
{
	if(L->last == MAXSIZE - 1)
		return -1;

	if(i < 0 || i > L->last+1 )
		return -2;

	int j = L->last;

	while(i <= j)
	{
		L->data[j+1] = L->data[j];
		j--;
	}	
	L->data[i] = *x;
	L->last ++;

	return 0;
}


int sqlist_delete(sqlist *L,int i,datatype *x)
{
	if(sqlist_is_empty(L))
		return -2;
	if(i < 0 || i > L->last)
		return -1;
	
	int j = i;

	*x = L->data[i];
	while(j <= L->last-1)
	{
		L->data[j] = L->data[j+1];
		j++; 
	}
	L->last --;
	return 0;
}

int sqlist_get(sqlist *L,int i,datatype *x)
{
	if(sqlist_is_empty(L))
		return -2;
	if(i < 0 || i > L->last)
		return -1;
	
	*x = L->data[i];
	return 0;
}

int sqlist_find(sqlist *L,datatype *x)
{
	int i = 0;

	while(i <= L->last)
	{
		if(*x == L->data[i])
			return i;
		i++;
	}
	return -1;
}

int sqlist_union(sqlist *L1 , sqlist *L2)
{
	int i;
	for(i = 0; i <= L2->last ; i++)
	{
		if(sqlist_find(L1,&L2->data[i]) == -1)
			sqlist_insert(L1, L1->last+1 , &L2->data[i]);
	}
}

int sqlist_is_empty(sqlist *L)
{
	return (L->last == -1);
}

void sqlist_set_empty(sqlist *L)
{
	L->last = -1;
}

void sqlist_display(sqlist *L)
{
	int i;
	if(sqlist_is_empty(L))
		return ;

	for(i = 0 ;i <= L->last ; i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}


void sqlist_destroy(sqlist *L)
{
	free(L);
}

























