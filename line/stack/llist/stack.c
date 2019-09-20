#include "stack.h"


STACK *stack_create(int size)
{
	return llist_create(size);
}

int stack_push(STACK *ptr,const void *data)
{
	return llist_insert(ptr,data,LLIST_FORWARD);  //栈后进先出，每次插入采用FORWARD
}

static int always_match(const void *key, const void *data)
{
	return 0;  //返回0代表
}

int stack_pop(STACK *ptr,void *data)
{
/*fetch函数要使第一次取出的data就是需要找到的数据，即要满足fetch函数内嵌套的find，cmp的条件*/
	return llist_fetch(ptr, (void *)0 , always_match,data);//第二个型参是假接口，第三个型参通过函数名调用函数。fetch函数原型正常结束返回值为0。
}


void stack_destroy(STACK *ptr)
{
	llist_destroy(ptr);
}



