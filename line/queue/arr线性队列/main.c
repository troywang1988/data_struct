i#include <stdio.h>

#include "queue.h"


int main()
{
	sequeue *sq;
	int i,ret;
	type arr[] = {1,3,5,7},tmp = 100;

	sq = queue_create();
	/*if error*/

	for(i = 0 ;i < sizeof(arr)/sizeof(*arr) ; i++)  //计算数组内元素个数，arr数组的大小除以数组arr内每个内容的大小
		queue_en(sq,&arr[i]);

	queue_display(sq);

	ret = queue_en(sq,&tmp);
	queue_display(sq);

	queue_destroy(sq);
	return 0;
}




