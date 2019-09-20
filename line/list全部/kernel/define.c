#include <stdio.h>

//#define MAX(a,b) ((a) > (b) ? (a) : (b))
//#define MAX(a,b) ({int A=(a),B=(b); A > B ? A:B; })
#define MAX(a,b) ({typeof(a) A=(a),B=(b); A>B?A:B; })


int main()
{
	int a = 3,b = 5;

	printf("MAX = %d\n",MAX(a++,b++));
	printf("a = %d,b = %d\n",a,b);


	return 0;
}


