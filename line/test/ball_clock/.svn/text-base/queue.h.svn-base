#ifndef MY_QUEUE_H__
#define MY_QUEUE_H__

typedef int type;
#define SIZE 32

typedef struct
{
	type data[SIZE];
	int front,rear;
}sequeue;

sequeue *queue_create();

int queue_en(sequeue *,type *);

int queue_de(sequeue *,type *);

void queue_display(sequeue *);

void queue_destroy(sequeue *);


#endif



