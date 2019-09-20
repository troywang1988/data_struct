#ifndef MY_LLIST_H__
#define MY_LLIST_H__

struct llist_node_st
{
	struct llist_node_st *prev,*next;
	char data[1];
};

typedef struct
{
	int size;
	struct llist_node_st head;
}LLIST;

#define LLIST_FORWARD  1
#define LLIST_BACKWARD 2

typedef void llist_op(void *);
typedef int llist_cmp(const void *,const void *);

LLIST *llist_create(int);

int llist_insert(LLIST * ,const void *data,int mode);

void *llist_find(LLIST *,const void *key,llist_cmp *);

int llist_delete(LLIST *,const void *key,llist_cmp *);

int llist_fetch(LLIST *,const void *key,llist_cmp *,void *);

void llist_travel(LLIST *, llist_op * );

void llist_destroy(LLIST *);

int llist_getnum(LLIST *);

#endif





