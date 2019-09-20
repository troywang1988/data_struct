#include "queue.h"

QUEUE *queue_create(int size)
{
	return llist_create(size);
}

int queue_en(QUEUE *ptr,const void *data )
{
	return llist_insert(ptr,data,LLIST_BACKWARD);  //队列先进先出，每次插入采用BACKWARD
}

static int always_match(const void *key,const void *data)
{
	return 0;
}

int queue_de(QUEUE *ptr,void *data)
{
	return llist_fetch(ptr,(void *)0,always_match,data);/*用data带回将要被删除的表元*/
}

void queue_destroy(QUEUE *ptr)
{
	llist_destroy(ptr);
}



