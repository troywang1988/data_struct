#ifndef MY_LLIST_H__
#define MY_LLIST_H__

typedef void LLIST;

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

#endif





