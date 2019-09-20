#include <stdio.h>

#include "queue.h"
#include "stack.h"

static int check(sequeue *sq)
{
	int i = (sq->front + 1) % SIZE;

	while(i != sq->rear)
	{
		if(sq->data[i] > sq->data[(i+1)%SIZE])
			return 0;
		i = (i + 1)%SIZE;
	}
	return 1;
}


int main()
{
	sequeue *sq;
	sqstack *st_min,*st_fivemin,*st_hour;
	int i,time,tmp,value;

	sq = queue_create();
	/*if error*/
	st_min = stack_create();	
	/*if error*/
	st_fivemin = stack_create();	
	/*if error*/
	st_hour = stack_create();	
	/*if error*/
	
	for(i = 1 ;i <= 27; i++)
		queue_en(sq,&i);
	queue_display(sq);
	
	while(1)
	{
		queue_de(sq,&tmp);
		time++;
	
		if(st_min->top != 3)
			stack_push(st_min,&tmp);
		else //st_min is full
		{
			while(!stack_is_empty(st_min))
			{
				stack_pop(st_min, &value);
				queue_en(sq,&value);
			}	
			
			if(st_fivemin->top != 10)
				stack_push(st_fivemin,&tmp);	
			else//st_fivemin is full
			{
				while(!stack_is_empty(st_fivemin))
				{
					stack_pop(st_fivemin, &value);
					queue_en(sq,&value);
				}  

				if(st_hour->top != 10)
					stack_push(st_hour,&tmp);
				else//st_hour is full
				{
					while(!stack_is_empty(st_hour))
					{
						stack_pop(st_hour, &value);
						queue_en(sq,&value);
					}
					
					queue_en(sq,&tmp);
					if(check(sq))
						break;						
				}
			}
			
		}


	}
	

	printf("time = %d\n",time);

	queue_display(sq);

	stack_destroy(st_min);
	stack_destroy(st_fivemin);
	stack_destroy(st_hour);
	queue_destroy(sq);

	return 0;
}




