#ifndef MY_LIST_H__
#define MY_LIST_H__

typedef int datatype;
#define MAXSIZE 1024

typedef struct
{
	datatype data[MAXSIZE];
	int last;
}sqlist;

/*
 *sqlist_create-create a sqlist
 *return : failed return NULL
 * */
sqlist *sqlist_create(void);
void sqlist_create1(sqlist **);

int sqlist_insert(sqlist *,int i,datatype *);

int sqlist_delete(sqlist *,int i,datatype *);
int sqlist_get(sqlist *,int i,datatype *);

int sqlist_find(sqlist *,datatype *);
int sqlist_union(sqlist *,sqlist *);

int sqlist_is_empty(sqlist *);
void sqlist_set_empty(sqlist *);

void sqlist_display(sqlist *);

void sqlist_destroy(sqlist *);

















#endif







