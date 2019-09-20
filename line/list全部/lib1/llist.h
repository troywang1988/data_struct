#ifndef MY_LLIST_H__
#define MY_LLIST_H__

struct llist_node_st
{
/*结构中的数据部分定义为空类型的指针*/
	void *data;
	struct llist_node_st *prev,*next;//双链表的两个指针
};

typedef struct
{
	int size;//结构的大小
	struct llist_node_st head;//结构嵌套
}LLIST;

#define LLIST_FORWARD  1   //有意义的插入：头插或尾插，定义开关
#define LLIST_BACKWARD 2

typedef void llist_op(void *);//定义llist_op函数，型参为void*，返回值为空

LLIST *llist_create(int);

int llist_insert(LLIST * ,const void *data,int mode);

//llist_find();

//llist_delete();

//llist_fetch();

void llist_travel(LLIST *, llist_op * );

void llist_destroy(LLIST *);

#endif





