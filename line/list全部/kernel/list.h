#ifndef MY_KERNEL_LIST_H__
#define MY_KERNEL_LIST_H__


struct list_head {
	struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)


static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}


#define __list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)







#define offsetof(TYPE, MEMBER) \ //TYPE 是一个结构体元；MEMBER是结构体的一个元素
		((size_t) &((TYPE *)0)->MEMBER)//将结构体元地址定义为0，计算MEMBER到0的相对偏移量

#define container_of(ptr, type, member) ({			\
	(type *)( (char *)ptr - offsetof(type,member) );})//得到实际地址值，强转为结构类型指针

/*
 *ptr->cur
 *type->struct score_st
 *member->node
 * */

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member) //




#endif








