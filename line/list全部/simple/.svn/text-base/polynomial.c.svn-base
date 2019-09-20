#include <stdio.h>
#include <stdlib.h>

/*h1 = 5 + 2x + 8x^8 + 6x^32
 *h2 = 6x + 5x^6 - 8x^8 
 * */

#define M (4)
#define N (3)

typedef struct poly_st
{
	int coef;
	int exp;
	struct poly_st *next;
}polylink;

polylink *poly_create(int a[][2], int n)
{
	polylink *h,*p,*q;
	int i;

	h = malloc(sizeof(*h));
	if(h == NULL)
		return NULL;
	h->next = NULL;

	p = h;

	for(i = 0 ;i < n ; i++)
	{
		q = malloc(sizeof(*q));
		/*if error*/
		q->coef = a[i][0];
		q->exp = a[i][1];
		q->next = NULL;	

		p->next = q;
		p = q;	
	}

	return h;
}

void poly_display(polylink *h)
{
	polylink *p = h->next;

	while(p)
	{
		printf("(%d,%d) ",p->coef,p->exp);
		p = p->next;
	}
	printf("\n");
}

void poly_union(polylink *h1,polylink *h2)
{
	polylink *p,*q,*r;

	p = h1->next;
	q = h2->next;	
	r = h1;

	while(p && q)
	{
		if(p->exp < q->exp)//h1 < h2
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
			if(p->exp > q->exp)//h1 > h2
			{
				r->next = q;
				r = q;
				q = q->next;
			}
			else	//h1 == h2
			{
				p->coef += q->coef;
				if(p->coef)
				{
					r->next = p;
					r = p;
				}
				p = p->next;
                q = q->next;
			}
	}
		
	if(p == NULL)
		r->next = q;
	else
		r->next = p;	
}

int main()
{
	int a[M][2] = {{5,0},{2,1},{8,8},{6,32}};
	int b[N][2] = {{6,1},{5,6},{-8,8}};
	
	polylink *L1,*L2;

	L1 = poly_create(a,M);
	L2 = poly_create(b,N);

	poly_display(L1);
	poly_display(L2);

	poly_union(L1,L2);
	poly_display(L1);

	return 0;
}


