#include"ch11.h"
int main()
{
	int s,r;
	pid_t pid1,pid2;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork pid1 error!\n");
		exit(-1);
	}
	else if(pid1==0)
	{
		printf("child1 :pid= %d,ppid= %d\n",getpid(),getppid());
		exit(0);
	}
	else{
		pid2=fork();
		if(pid2<0)
		{
			perror("fork pid2 error!\n");
			exit(-1);
		}
		else if(pid2==0)
		{
			printf("child 2:pid=%d,ppid=%d\n",getpid(),getppid());
			exit(0);
		}
		else{
			int r,s;
			r=wait(NULL);
			s=wait(NULL);
			printf("r=%d,s=%d\n",r,s);
		}}
		

}
