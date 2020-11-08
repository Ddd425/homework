#include"./ch07.h"
static void callback1(void)
{
	printf("----Callback1----\n");
}
static void callback2(void)
{
	printf("----Calllback2----\n");
}
static void callback3(void)
{
	printf("----Callback3----\n");
}
int main(void)
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	while(1)
	{
		sleep(1);
	}

	printf("----Main exit!----\n");
	exit(0);
	//_exit(0);
}
