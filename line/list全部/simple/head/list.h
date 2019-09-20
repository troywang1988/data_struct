#ifndef MY_LIST_H__
#define MY_LIST_H__

typedef int datatype;

typedef struct list_st
{
	datatype data;
	struct list_st *next;
}linklist;

linklist *linklist_creat();
int linklist_insert(linklist *,int i,datatype *);
int linklist_order_insert(linklist *,datatype *);
  
int linklist_delete(linklist *,datatype *);
int linklist_delete_at(linklist *,int i,datatype *);
  
void linklist_display(linklist *);
void linklist_destroy(linklist *);
void linklist_reverse(linklist *);
 
 
#endif

