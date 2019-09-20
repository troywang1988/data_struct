#include <stdio.h>
#include "stack.h"

static compute(sqstack *snum,int ope)
{
	int n1,n2,n;

	stack_pop(snum,&n1);
	stack_pop(snum,&n2);

	switch(ope)
	{
		case '+':	n = n1 + n2;	break;
		case '-':	n = n2 - n1;	break;
		case '*':	n = n1 * n2;	break;
		case '/':	n = n2 / n1;	break;
	}
	stack_push(snum,&n);
}


static deal_bracket(sqstack *snum,sqstack *sope)
{
	int old_ope;

	stack_top(sope,&old_ope);

	while(old_ope != '(')
	{
		stack_pop(sope,&old_ope);
		compute(snum,old_ope);
		stack_top(sope,&old_ope);
	}
	stack_pop(sope,&old_ope);
}

static int get_pri(int ope)
{
	switch(ope)
	{
		case '(':	return 0;
		case '+':	
		case '-':	return 1;
		case '*':	
		case '/':	return 2;
	}
}

static deal_ope(sqstack *snum,sqstack *sope,int ope)//(+-*/
{
	int old_ope;
	if(ope == '(' || stack_is_empty(sope))
	{
		stack_push(sope,&ope);
		return ;
	}

	stack_top(sope,&old_ope);
	if(get_pri(ope) > get_pri(old_ope))
	{
		stack_push(sope,&ope);
		return ;
	}
			//	-				* +			
	while(get_pri(ope) <= get_pri(old_ope))
	{
		stack_pop(sope,&old_ope);
		compute(snum,old_ope);
		if(stack_is_empty(sope))
			break;
		stack_top(sope,&old_ope);
	}	
	stack_push(sope,&ope);
	
}

int main()
{
	int i,old_ope;
	sqstack *snum,*sope;
	char str[] = "12+3*(8-4)-5";
	int value = 0,flag = 0;

	snum = stack_create();
	/*if error*/
	sope = stack_create();
	/*if error*/

	while(str[i] != '\0')
	{	//12  '1'-->1  '2'-->1*10+2
		if(str[i] >= '0' && str[i] <= '9')//is a num
		{
			value = value * 10 + str[i] - '0';	
			flag = 1;
		}
		else//is a ope
		{
			if(flag)
			{
				stack_push(snum,&value);
				value = 0;	
				flag = 0;
			}
			if(str[i] == ')')
			{
				deal_bracket(snum,sope);
			}
			else//(+-*/
			{
				deal_ope(snum,sope,str[i]);
			}
		}
		i++;
	}	

	if(flag)
		stack_push(snum, &value);

	if(!stack_is_empty(sope))
	{
		stack_pop(sope,&old_ope);
		compute(snum,old_ope);	
	}
	
	stack_pop(snum,&value);

	printf("%s = %d\n",str,value);

	stack_destroy(snum);
	stack_destroy(sope);

	return 0;
}



