#include"ch12.h"
int main()
{
	pid_t k1,k2;
	int fd1[2],fd2[2],i;
    	
	char buf[100];
	memset(buf,0,sizeof(buf));
	if((pipe(fd1))<0||pipe(fd2)<0)
		{
		 perror("pipe failed!\n");
		exit(-1);
		}
	k1=fork();
	if(k1<0)
	{
		perror("fork1 failed!\n");
		exit(-1);
	}
	else if(k1==0)
	{
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"%d:%d child 1say hello\n",getppid(),getpid());
		write(fd1[1],buf,sizeof(buf));
		sleep(1);
		read(fd2[0],buf,sizeof(buf));
		printf("%d:child 1 %s\n",getppid(),buf);
		exit(0);
	}
	else 
	{
		k2=fork();
		if(k2<0)
		{
			perror("fork2 failed!\n");
			exit(-1);
		}
		else if(k2==0)
		{
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0],buf,sizeof(buf));
		printf("%d :child 2 %s\n",getppid(),buf);
		sprintf(buf,"%d:%d child 2 say ok  \n",getppid(),getpid());
		write(fd2[1],buf,sizeof(buf));
		exit(0);

		}
		else
		{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);
			wait(NULL);
			wait(NULL);
			return 0;
		

		}

	}

}
