#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<dlfcn.h>
void err_exit(char *s)
{
	printf("Usage:%s si failed!\n",s);
	exit(0);
}
