#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main()
{
FILE *fp;
fp=fopen("./test1.txt","w");
printf("file fd=%d\n",fp->_fileno);
fclose(fp);
return 0;
}
