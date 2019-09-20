#include <stdio.h>
#include <stdlib.h>

typedef struct josephu_st
{
	int data;
	struct josephu_st *next;
}josephu;


josephu *jose_create(int n)
{
	josephu *L,*p,*q;
	int i = 1;

	L = malloc(sizeof(*L));
	if(L == NULL)
		return NULL;
	L->data = i;
	L->next = L;

	i++;
	p = L;
	
	while(i <= n)
	{
		q = malloc(sizeof(*q));
		/*if error*/
		q->data = i;
		q->next = L;
	
		p->next = q;
		p = q;	
	
		i++;
	}
	return L;
}

void jose_display(josephu *L)
{
	josephu *p = L;

	while(p->next != L)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}

void jose_kill(josephu **L,int n)
{
	int i = 1;
	josephu *p = *L,*q;

	while(p->next != p)
	{	
		while(i < n)
		{
			q = p;
			p = p->next;
			i++;
		}
		q->next = p->next;
		printf("%d ",p->data);
		free(p);
		
		p = q->next;
		i = 1;
	}
	*L = p;
	printf("\n");
}

int main()
{
	int n = 8,m = 3;
	josephu *L;

	L = jose_create(8);
	/*if error*/

	jose_display(L);

	jose_kill(&L,m);
	jose_display(L);

	return 0;
}



