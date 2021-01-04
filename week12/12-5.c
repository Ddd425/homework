#include"ch12.h"
int main(void)
{
	int pid,fd[2],r;
	char buf[100];
	memset(buf,0,sizeof(buf));
	if(pipe(fd)<0)
		{
		 perror("pipe failed!\n");
		exit(-1);
		}
	pid=fork();
	if(pid<0)
		perror("fork failed!\n");
	else if(pid==0)
	{
		close(0);
		close(fd[1]);
		dup(fd[0]);
		r=execl("./test","./test","hello","world","2020",NULL,NULL);
    		if(r==-1)
    		{
	    		perror("execl failed\n");
	    		exit(-1);
   		 }
	}
	else
	{
	 
	 close(fd[0]);
         printf("%d : \n",getpid());
       
	while(gets(buf)!=NULL)
       puts(buf);
	return 0;
	}
}

