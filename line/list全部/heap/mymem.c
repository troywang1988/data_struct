#include <stdio.h>
#include <stddef.h>

#include "mymem.h"

struct mymem_node_st
{
	struct mymem_node_st *prev,*next;
	char *end;  //end指针就是指向内存中一个普通地址用的，而结构中的prev和next是指向与他类型相同的结构体地址的
};

#define MIN_NODE_SIZE ((sizeof(struct mymem_node_st) + (MAX_ALIGN-1)) & ~(MAX_ALIGN-1))

#define RECEIVE_SIZE  32  //当截取后剩余空间达到该值，则留下剩余空间继续管理，若小于该值则都分给客户

static void *align_down(void *p)  //区域内向下对齐边界
{
	return (void *)((size_t)p & ~(MAX_ALIGN - 1));	
}
static void *align_up(void *p)  //区域内向上对齐边界
{
	return (void *)(((size_t)p + MAX_ALIGN-1) & ~(MAX_ALIGN - 1));	
}

static int align_size(int size)  //将客户申请的size大小做向上对齐
{
	return ((size + MAX_ALIGN-1) & ~(MAX_ALIGN - 1));	
}

/*建立带头循环双链表，表中除头节点外，头节点后还有一个节点*/
void *mymem_init(void *ptr,int size)
{
	char *start,*end;
	struct mymem_node_st *head,*node;

	start = ptr;	
	end = start + size;
	printf("%p , %p\n",start,end);

	start = align_up(start);
	end = align_down(end);
	printf("%p , %p\n",start,end);

	head = (struct mymem_node_st *)start;
	node = align_up(head+1);  //head是刚经过对齐计算的可用空间起始地址,被强制转换成结构体的指针，做了链表的头节点，node为与头相邻的头后第一节点

	head->prev = head->next = node;
	head->end = (char *)node;//head->end的类型为char*
	
	node->prev = node->next = head;
	node->end = end;  //end为整个空间尾地址指针

	return head;  //返回表头地址
}

/*计算实际分配size的大小*/
static int alloc_size(int size)
{
	size = align_size(size) + align_size(sizeof(void *));//加一个隐藏分配单元尾地址的空间
	
	return (size > MIN_NODE_SIZE ? size : MIN_NODE_SIZE);
}

static int node_size(struct mymem_node_st *node)
{
	return (node->end - (char *)node);
}

static struct mymem_node_st *find_(struct mymem_node_st  *handle,int size)
{
	struct mymem_node_st *cur,*min = handle;//由于应用受限min在定义时刻没有和似的初始化赋值，这里给它加了标记handle，使之不成为野指针

	for(cur = handle->next ;cur != handle ; cur = cur->next)
		if(node_size(cur) >= size) //如果当前表元大小满足条件
			if(min == handle || node_size(cur) < node_size(min))  //if中第一个条件是为了让if在第一次循环判断时条件成立，执行下面语句，使min得到新值。在第二次for循环时，该if语句中第一个条件永不再成立
				min = cur;
			
	return min;  //不论是否有满足条件的表元，最后都会返回min
}

static void *mem2usr(void *start,void *end)
{
	void **ptr = start;  //ptr指向首地址指针start
	
	*ptr = end;  //将尾指针end装入*ptr中，即，装入

	return align_up(ptr + 1);  //得到从start开始留出一个记录end地址空间后地址指针，返回给客户
}

/*本函数每次都在以handle开始的这段区域内给客户分配空间，故型参中不仅有size,还有handle*/
void *mymem_myalloc(void *handle,int size)//handle是init函数的返回地址－表的首地址
{
	int sub;
	void *start,*end;
	struct mymem_node_st *node;

	size = alloc_size(size);  //先计算出实际分配的size大小

	node = find_(handle,size);  //遍历链表查找最满足条件的最合适表元
	if(node == handle)  //说明遍历一圈，没有找到满足条件的，min仍然指向handle
		return NULL;

	end = node->end;  //用void *end,记录node->end
	sub = node_size(node) - size;  //用find到的空间大小减去实际应分配的空间大小，判断是否大于阀值，大于则回收空间差值，继续管理

	if(sub < RECEIVE_SIZE)//all
	{
		node->prev->next = node->next;  //剥离表元node
		node->next->prev = node->prev;
		start = node;  //赋值给结构体指针start
	}
	else
	{
		node->end -= size;  //移动node->end得到一块size大小的新空间，node在链表中位置不变
		start = node->end;  //返回给客户的空间从node->end开始。这里是char *型指针给void *型指针赋值
	}

	return mem2usr(start,end);
}

static struct mymem_node_st *usr2mem(char *ptr)
{
	struct mymem_node_st *node;
	void **end;

	node = (struct mymem_node_st *)(ptr - align_size(sizeof(void *)));
	/*ptr是给客户的指针，减掉一个指针类型的大小，使node指向装有该返回空间end地址的空间地址*/
	
	end = (void **)node;  //node被强转为2级指针，给end赋值

	node->end = *end;
	return node;
}

static void  insert_(struct mymem_node_st *handle,struct mymem_node_st  *node)
{
	struct mymem_node_st *cur;

	for(cur = handle->next ;cur < node && cur != handle; cur = cur->next)
		;

	node->next = cur;
	node->prev = cur->prev;
	node->next->prev = node;
	node->prev->next = node;
}

static void  merge(struct mymem_node_st *handle,struct mymem_node_st  *node)
{
	
	if((char *)node->next == node->end)//BACK
	{
		node->end = node->next->end;
		node->next = node->next->next;
		node->next->prev = node;
	}
	if(node->prev != handle && (char *)node == node->prev->end)
	{
		node = node->prev;		
		node->end = node->next->end;
        node->next = node->next->next;
        node->next->prev = node;
	}
}

void mymem_myfree(void *handle,void *ptr)
{
	struct mymem_node_st *node;	

	node = usr2mem(ptr);

	insert_(handle,node);

	merge(handle,node);

}



void mymem_destroy(void *ptr)
{
//memset()
//bzero()
}










