#include <stdio.h>
#include <stdlib.h>//引用malloc函数
#include <string.h>//系统的字符串处理库，本程序引用：strcmp函数

#include "llist.h"

/*函数llist_creat,型参是整形的size,返回值是LLIST结构类型的指针*/
LLIST *llist_create(int size)
{
	LLIST *new;

	new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;
	
	new->size = size;//定义了一块size空间,size空间分配的大小，与型参值有关，若为0则不分配内存空间给size元素
	new->head.data = NULL;
	new->head.prev = new->head.next = &new->head;

	return new;
}

/*调用一次insert函数就在链表中加入一个新表元*/
int llist_insert(LLIST *ptr ,const void *data,int mode)//用户传指向他数据地址的指针过来，我们在函数型参中用const void*指针来接收，可确保接收到客户传来的数据指针是任意类型，同时不能够修改该指针值
{
	struct llist_node_st *newnode;//定义新的结构指针,它不同于首节点，只有一个data域和两个指针域

	newnode = malloc(sizeof(*newnode));//该新类型的大小是3个指针型所占内存的大小，即12个字节
	if(newnode == NULL)
		return -1;

	newnode->data = malloc(ptr->size);//为新节点data域分配相应大小的数据存储空间（是挂在节点外面的，由节点内的data域里的指针指向）
	if(newnode->data == NULL)
	{
		free(newnode);
		return -2;
	}
	memcpy(newnode->data ,data, ptr->size);//将型参中指针data开始的ptr->size大小的区域里的数据复制到newnode->data开始的内存中

	if(mode == LLIST_FORWARD) //通过mode值判断客户要求的插入位置
	{
		newnode->prev = &ptr->head;//head本身是一个结构体变量，被嵌套使用在ptr指向的结构体内部。本句是取head结构体的地址赋值给新节点的prev指针
		newnode->next = ptr->head.next;
	}/*head->prev仍指向自身，没有改变*/
	else
		if(mode == LLIST_BACKWARD)
		{
			newnode->prev = ptr->head.prev;//新节点的prev指向的是该链表的最后节点，最后节点的地址始终会保存在头节点的prev里
			newnode->next = &ptr->head;
		}
		else
		{
			return -3;
		}
/*处理新插入节点的前后两个节点的变化的指针指向*/
	newnode->prev->next = newnode;//新插入节点前面的的节点的next指向将发生变化，指向新节点
	newnode->next->prev = newnode;//新插入节点后面的节点的prev将发生变化，指向新节点
	
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

		free(cur->data);
		free(cur);
		cur = NULL;
	}
	
	free(ptr);

}






