#include"../ch07.h"
int main()
{
	char s[128];
//需要用memset清楚
	strcpy(s,"hello world!");
	printf("s=%s\n",s);
	return 0;
}
