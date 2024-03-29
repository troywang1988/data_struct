#ifndef MY_LLIST_H__
#define MY_LLIST_H__

#define LLIST_FORWARD  1
#define LLIST_BACKWARD 2
typedef void llist_op(void *);
typedef int llist_cmp(const void *,const void *);

struct llist_node_st
{
	struct llist_node_st *prev,*next;
	char data[1];
};

typedef struct llist_head_st
{
	int size;
	struct llist_node_st head;
	int (*insert)(struct llist_head_st * ,const void *data,int mode);
	void *(*find)(struct llist_head_st *,const void *key,llist_cmp *);
	int (*delete)(struct llist_head_st *,const void *key,llist_cmp *);
	int (*fetch)(struct llist_head_st *,const void *key,llist_cmp *,void *);
	void (*travel)(struct llist_head_st *, llist_op * );
}LLIST;

LLIST *llist_create(int);

void llist_destroy(LLIST *);

#endif





