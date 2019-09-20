#ifndef MY_QUEUE_H__
#define MY_QUEUE_H__

#include "llist.h"
typedef LLIST QUEUE;  //宏替换，形式上使用QUEUE，而实际在用LLIST作函数的处理对象

QUEUE *queue_create(int );

int queue_en(QUEUE *,const void * );

int queue_de(QUEUE *,void *);

void queue_destroy(QUEUE *);

#endif
