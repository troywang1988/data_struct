#include <stdio.h>
#include <signal.h>


void fun_alarm(int s)
{
	alarm(1);
	printf("GET SIGALRM!\n");
}

int main()
{
	signal(SIGALRM,fun_alarm);
	alarm(3);

	while(1)
	{
		printf("while(1)\n");
		sleep(1);
	}

	return 0;
}




