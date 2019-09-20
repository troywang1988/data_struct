#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main()
{
	int c;
	struct termios old,new;

	tcgetattr(0,&old);
	tcgetattr(0,&new);

	new.c_lflag = new.c_lflag & ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;

	tcsetattr(0,TCSANOW ,&new);
	while(1)
	{
		c = getchar();
		if(c == 'Q')
			break;
		printf("%d ",c);
		fflush(NULL);
	}	

	tcsetattr(0,TCSANOW ,&old);



	return 0;
}











