#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

LLIST *llist_create(int size)
{
	LLIST *new;

	new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;
	
	new->size = size;
	new->head.prev = new->head.next = &new->head;

	return new;
}

int llist_insert(LLIST *ptr ,const void *data,int mode)
/*参数分别是结构体指针，待插入数据域的指针和插入的位置*/
{
	struct llist_node_st *newnode;

	newnode = malloc(sizeof(*newnode)+ptr->size);
	if(newnode == NULL)
		return -1;

	memcpy(newnode->data ,data, ptr->size);

	if(mode == LLIST_FORWARD)
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
	}
	else
		if(mode == LLIST_BACKWARD)
		{
			newnode->prev = ptr->head.prev;
			newnode->next = &ptr->head;
		}
		else
		{
			return -3;
		}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	
	return 0;
}

static struct llist_node_st *find_(LLIST *ptr,const void *key,llist_cmp *cmp)
{
	struct llist_node_st *cur;
	
	for(cur = ptr->head.next;cur != &ptr->head ; cur = cur->next)
	{
		if(cmp(key,cur->data) == 0)  //cmp是在主函数中由客户完成的函数，其功能属于接口函数，传递一种需求。型参1是客户传过来要查找的一种结构体元素指针，型参2是链表的data域，我们传递给客户，供他完成cmp
			break;
	}	
	return cur;
}

void *llist_find(LLIST *ptr,const void *key,llist_cmp *cmp)
{
	struct llist_node_st *node;

	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return NULL;
	return node->data;

}
int llist_delete(LLIST *ptr,const void *key,llist_cmp *cmp)
{
	struct llist_node_st *node;

	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;
	
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);

	return 0;
}
int llist_fetch(LLIST *ptr,const void *key,llist_cmp *cmp,void *data)
{
	struct llist_node_st *node;

	node = find_(ptr,key,cmp);
	if(node == &ptr->head)  //&ptr->head是find_函数中，for循环的终止条件，若if为真，说明没用找到
		return -1;
	
	memcpy(data,node->data,ptr->size);	//否则将找到的node赋值给data
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);

	return 0;
}

void llist_travel(LLIST *ptr,llist_op *op)
{
	struct llist_node_st *cur;
	
	for(cur = ptr->head.next;cur != &ptr->head ; cur = cur->next)
		op(cur->data);
}

void llist_destroy(LLIST *ptr)
{
	struct llist_node_st *cur,*node;
	
	for(cur = ptr->head.next;cur != &ptr->head ; cur = node)
	{
		node = cur->next;		

		free(cur);
		cur = NULL;
	}
	
	free(ptr);

}






