#include <stdio.h>

#include "list.h"

int main()
{
	sqlist *L,*L1;
	datatype a[] = {1,3,5,7,9},tmp = 100;
	datatype b[] = {1,2,3,4,5,6,7,8};
	int i,ret;

	L = sqlist_create();
	if(L == NULL)
		return -1;
	L1 = sqlist_create();
	if(L1 == NULL)
		return -1;

	for(i = 0 ;i < sizeof(a)/sizeof(*a) ; i++)
		sqlist_insert(L,0,&a[i]);
	sqlist_display(L);
	for(i = 0 ;i < sizeof(b)/sizeof(*b) ; i++)
		sqlist_insert(L1,0,&b[i]);
	sqlist_display(L1);
#if 0
	ret = sqlist_delete(L,30,&tmp);
	if(ret == 0)
	{
		printf("DELETE:%d\n",tmp);
		sqlist_display(L);
	}
	else
		printf("DELETE ERROR,errno:%d\n",ret);
#endif

	sqlist_union(L,L1);
	sqlist_display(L);

	sqlist_destroy(L);
	sqlist_destroy(L1);

	return 0;
}








