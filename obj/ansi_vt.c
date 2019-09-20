#include <stdio.h>

int main()
{
	printf("\033[2J\033[1;1H\033[4;31mhello\n\033[0m");	
	sleep(1);

	return 0;
}


