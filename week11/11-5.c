#include"ch11.h"
int main()
{
	pid_t pid1;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork pid1 error!\n");
		exit(-1);
	}
	else if(pid1==0)
	{
		printf("child1: pid=%d, ppid=%d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		pid_t pid2;
		pid2=fork();
		if(pid2<0)
		{
			perror("fork pid2 error!\n");
			exit(-1);
		}
		else if(pid2==0)
		{
			printf("child2: pid=%d, ppid=%d\n",getpid(),getppid());
			while(1)
			printf("running!\n");
			exit(0);
		}
		else{
			int s1,r1,s2,r2;
			r1=waitpid(pid1,&s1,0);
			r2=waitpid(pid2,&s2,0);

			if(WIFEXITED(s1))
			{
				printf("child1 exit nomaly! exit code %d\n",WEXITSTATUS(s1));
			}
			else
			{
				
				printf("child 1 exit abnamaly!exit with signal  %d\n",WTERMSIG(s1));
			}
			if(WIFEXITED(s2))
			{
				printf("child2 exit nomaly! exitcode %d\n",WEXITSTATUS(s2));
			}
			else

			{
				printf("child2 exit abnomaly! exit signal %d\n",WTERMSIG(s2));
			}
			printf("parent ended!\n");
			return 0;
		}
		}	
}

