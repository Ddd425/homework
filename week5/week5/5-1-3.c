#include"ch05.h"
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	printf("Hello world");
	while(1);
	return 0;
}
