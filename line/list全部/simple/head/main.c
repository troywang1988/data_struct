#include<stdio.h>
#include"list.h"

int main()
{
	int i;
	datatype arr[] = {31,3,5,7,9},tmp = 100,tt;
	linklist *L;
	L = linklist_creat();
	
	if(L == NULL)
	{
		printf("creat error!");
		return -1;
	}
	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
	{
		linklist_order_insert(L,&arr[i]);
	}
	linklist_display(L);

	linklist_insert(L,2,&tmp);
	linklist_display(L);

    linklist_delete(L,&tmp);

	linklist_delete_at(L,3,&tt);
	printf("delete->num is :%d\n",tt);
	linklist_display(L);

	linklist_reverse(L);

	linklist_destroy(L);

	return 0;
}
