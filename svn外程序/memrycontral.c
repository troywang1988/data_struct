#include<stdio.h>

#include"memrycontral.h"

define n 4


struct head *s_head(char *q,)
{
	char *s = q;//用指针s接收指针q，进行运算
	struct head *p;
	int i;	

	for(i = &q;;i++)
	{
		if(i % n == 0)
		s  = &q + i;
		break;
	}

	p = (struct head *)s;
	p->pre = p;
	p->next = p;
	p->end = & ch[1024];

	return p;
}

struct head *mymalloc(int size)
{
	struct head *p,*r;
	char *del,*ret;
	p = s_head;
	while(size % n == 0)
	{
		size++;
	}
	size+ = 3*(sizeof(char*));//计算应该划分的size大小
	del = p->end - size;
	if(p->end - p >= size + sizeof(char));
	r = (struct head *)del;//划分出来的一个单元内的指针需要初始化吗？
	p->end = &r - sizeof(char);
	ret = &r - 3*sizeof(char);
	
	return ret;

	else
	return find(struct head *s,size);
}

struct head *find(struct head *s,int size)
{
	struct head *fd;
//	fd = s;
	int i,j = 0; 
	struct head *mem,*nen;
	
	for(fd = s;fd->next != s;fd = fd->next->next)
	{
		mem = s;
		nen = mem + 1;
		i = &(mem->end) - &(mem->pre);
		j = &(nen->end) - &(nen->pre);
		if(i >= size && j >= size)
			if(i < j)
				nen = mem;
		j = i;
		mem = fd->pre
	}
}
