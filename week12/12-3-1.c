#include"ch12.h"
int main()
{
	pid_t k1,k2;
	k1=fork();
	if(k1<0)
	{
		perror("fork1 failed!\n");
		exit(-1);
	}
	else if(k1==0)
	{

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

		}
		else
		{
			wait(NULL);
			wait(NULL);
			return 0;
		

		}

	}

}
