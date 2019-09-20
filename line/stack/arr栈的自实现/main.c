#include "stack.h"


int main()
{
	sqstack *st;
	int i;
	datatype arr[] = {1,3,5,7,9},tmp = 100;	

	st = stack_create();
	/*if error*/

	for(i = 0 ;i < sizeof(arr)/sizeof(*arr); i++)
		stack_push(st,&arr[i]);
	stack_display(st);


	stack_destroy(st);

	return 0;
}
