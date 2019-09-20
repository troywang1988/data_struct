#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

sqstack *stack_create()
{
	sqstack *st;

	st = malloc(sizeof(*st));
	if(st == NULL)
		return NULL;
	st->top = -1;
	return st;
}
int stack_is_empty(sqstack *st)
{
	return (st->top == -1);
}

int stack_push(sqstack *st,datatype *x)
{
	if(st->top == MAXSIZE - 1)
		return -1;
	st->data[++st->top] = *x;
	return 0;
}

int stack_pop(sqstack *st,datatype *x)
{
	if(st->top == -1)
		return -1;
	*x = st->data[st->top--];
	return 0;
}

int stack_top(sqstack *st,datatype *x)
{
	if(st->top == -1)
		return -1;
	*x = st->data[st->top];
	return 0;
}

void stack_display(sqstack *st)
{
	int i;
	for(i = 0 ;i <= st->top ; i++)
		printf("%d ",st->data[i]);
	printf("\n");
}

void stack_destroy(sqstack *st)
{
	free(st);
}




