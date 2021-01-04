#include"./ch10.h"
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("error!\n");
		exit(-1);
	}
	else if (pid==0)
		{
			printf("child %d is running!\n",getpid());
			while(1);
		}
	else
	{
		getchar();
		printf("parent %d will exit now!\n",getpid());
		exit(0);
		}
}

