#include <stdio.h>

#include <llist.h>

#define NAMESIZE 32
#define DATA_NR 4096
#define LIST_NR 127
struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

static LLIST *list[LIST_NR];

static int id_cmp(const void *key,const void *data)
{
	const int *k = key;
	const struct score_st *d = data;
	
	return (*k - d->id);

}
void print_s(struct score_st *d)
{
	printf("%d %s %d\n",d->id,d->name,d->math);
}

int list_init()
{
	int i,j;

	for(i = 0 ;i < LIST_NR; i++)
	{
		list[i] =llist_create(sizeof(struct score_st));
		if(list[i] == NULL)
		{
			for(j = 0 ; j < i; j++)
				llist_destroy(list[j]);
			return -1;
		} 
	}
	return 0;
}

static int hash(int num)
{
	return (num % LIST_NR);
}

int insert(struct score_st *data)
{
	int ind;

	ind = hash(data->id);
	
	return llist_insert(list[ind] , data,LLIST_FORWARD); 
}

struct score_st *find(int id)
{
	int ind;

	ind = hash(id);

	return llist_find(list[ind],&id,id_cmp);

}


void travel()
{
	int i;

	for(i = 0 ;i < LIST_NR ;i++)
		printf("%d ",llist_getnum(list[i]));
	printf("\n");
}

int main()
{
	int i;
	struct score_st tmp,*datap;
	
	list_init();
	srand(getpid());

	for(i = 0 ;i < DATA_NR; i++)
	{
		tmp.id = rand();
		tmp.math = 100 - i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);

		insert(&tmp);
	}
	
	travel();

#if 0
	datap = find(5000);
	if(datap == NULL)
		printf("can not find!\n");
	else
		print_s(datap);
#endif

	return 0;
}


