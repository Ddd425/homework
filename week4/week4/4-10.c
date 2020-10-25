#include"ch03.h"
int main()
{
	FILE *fp;
	int fd;
	fp=fopen("./ch02.h","r");
	fd=fileno(fp);
	printf("fd=%d\n",fd);
	return 0;
}

