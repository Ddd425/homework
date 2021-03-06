#include"./ch13.h"
int main()
{
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K];

	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));
	memset(c,'c',sizeof(c));
	pid_t pid;
	int pipefd[2];
	int ret;
	ret=pipe(pipefd);
	if(ret==-1)
	{
		fprintf(stderr,"failed to create pipe (%s)\n",strerror(errno));
		return 1;
	}
	pid=fork();
	if(pid==0)
	{
		close(pipefd[0]);
		int loop=0;
		while(loop++<10)
		{
			ret=write(pipefd[1],a,sizeof(a));
			printf("apid=%d write %d bytes to pipe \n",getpid(),ret);
		}
		exit(0);
	}

	pid=fork();
	if(pid==0)
	{
		close(pipefd[0]);
		int loop=0;
		while(loop++<10)
		{
			ret=write(pipefd[1],b,sizeof(b));
			printf("apid=%d write %d bytes to pipe \n",getpid(),ret);
		}
		exit(0);
	}
	
	pid=fork();
	if(pid==0)
	{
		close(pipefd[0]);
		int loop=0;
		while(loop++<10)
		{
			ret=write(pipefd[1],c,sizeof(c));
			printf("apid=%d write %d bytes to pipe \n",getpid(),ret);
		}
		exit(0);
	}
	close(pipefd[1]);
	sleep(1);
	int fd=open("./test.dat",O_WRONLY|O_CREAT|O_TRUNC,0644);
	char buf[1024*4]={0};
	int n=1;
	while(1)
	{
		ret=read(pipefd[0],buf,sizeof(buf));
		if(ret==0) break;
		printf("n=%2d pid=%d read %d bytes from pipe buf[4095]=%c\n",n++,getpid(),ret,buf[4095]);
		write(fd,buf,ret);
	}
	return 0;
}


