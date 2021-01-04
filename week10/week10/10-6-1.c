#include"./ch10.h"
int main()
{
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("10-6 child:pid=%d,ppid=%d\n",getpid(),gettpid());
		execl("./test","./test","Hello","World",NULL);
		printf("10-6 child end!\n");
                exit(1);
	}
	else
	{
		int s,r;

		r=wait(&s);
		printf("10-6: r=%d,status=%d\n",r,EXITSTATUS(s));
		return 0;
	}
}
