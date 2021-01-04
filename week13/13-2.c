#include"ch13.h"
int main()
{
	int fifo_fd,n,total_bytes=0;
	char readbuf[PIPE_BUF];
	if(access(FIFO_FILE,F_OK)==-1)
		
	if(mkfifo(FIFO_FILE,0666)!=0)
	{
		printf("Could not create fifo %s\n",FIFO_FILE);
		exit(-1);
	}
	if((fifo_fd=open(FIFO_FILE,O_RDONLY/*O_NONBLOCK//非阻塞*/))<0)
	{
		printf("Could not open file %s\n",FIFO_FILE);
		exit(-1);
	}
	printf("Parent %d 's child %d opened: %s\n",getppid(),getpid(),FIFO_FILE);
	while((n=read(fifo_fd,readbuf,PIPE_BUF))>0)
	{
		printf("%d received %d bytes\n",getpid(),n);
		total_bytes +=n;
	}
	close(fifo_fd);
	unlink(FIFO_FILE);
	printf("Process %d received total %d bytes \n",getpid(),total_bytes);
	return 0;
}

