#include <stdio.h>
#include "mymem.h"

#define MEMSIZE 1023

static char mem[MEMSIZE];

int main()
{
	void *handle;
	void *arr[16];
	int i;

	handle = mymem_init(mem,MEMSIZE);
	

	for(i = 0 ;i < 16 ; i++)
	{
		arr[i] = mymem_myalloc(handle,64);
		printf("arr[%d] = %p\n",i,arr[i]);
		if(arr[i] == NULL)
			break;
	}
	
	mymem_myfree(handle,arr[3]);
	mymem_myfree(handle,arr[5]);
	mymem_myfree(handle,arr[4]);
	
	arr[15] = mymem_myalloc(handle,200);
	printf("arr[15] = %p\n",arr[15]);

	mymem_destroy(handle);
	return 0;
}














