#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

sequeue *queue_create()
{
	sequeue *sq;

	sq = malloc(sizeof(*sq));
	if(sq == NULL)
		return NULL;
	sq->front = sq->rear = 0;
	return sq;
}

int queue_en(sequeue *sq ,type *x)
{
	if((sq->rear + 1)%SIZE == sq->front)
		return -1;
	sq->rear = (sq->rear + 1)%SIZE;
	sq->data[sq->rear] = *x;
	
	return 0;
}

int queue_de(sequeue *sq,type *x)
{
	if(sq->front == sq->rear )
		return -1;

	sq->front = (sq->front+1)%SIZE;
	*x = sq->data[sq->front];
	return 0;
}

void queue_display(sequeue *sq)
{
	int i = (sq->front + 1)%SIZE;
	
	while(i != sq->rear)
	{
		printf("%d ",sq->data[i]);
		i = (i + 1) %SIZE;
	}
	printf("%d\n",sq->data[i]);

}

void queue_destroy(sequeue *sq)
{
	free(sq);
}

