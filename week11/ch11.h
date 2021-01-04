#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<setjmp.h>
#include<errno.h>
#include<wait.h>
#include<dlfcn.h>

#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH


FILE *fp;

void err_exit(char *s)
{
	printf("USAGE: *s is faile!\n");
	exit(1);
}
void info(int x,int y)
{     
        struct tm *t;
	time_t tt;
     	time(&tt);
     	t = localtime(&tt);
	fprintf(fp,"child%d pid=%d exittime:  %4d年%02d月%02d日 %02d:%02d:%02d\n", x,y,t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	
}
