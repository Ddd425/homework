#include"ch11.h"

int main()
{

        fp=fopen("./log.dat","w+");
	int r1,r2;
	r1=fork();
	if(r1<0)
	{
		perror("fork1 failed!\n");
	        exit(-1);
	}
	 else if (r1==0)
	 {
		 int r11;
		 r11=fork();
		 if(r11<0)
		 {	 perror("r11 fork failed!\n");
			 exit(-1);
		 }
		 else if(r11==0)
		 {

		 	printf("child11:pid=%d,ppid=%d\n", getpid(),getppid());
		 	
			exit(0);
	         } 
	
		 else 
	 	 {
			wait(NULL);
			info(11,r11);
			printf("child1 :pid=%d,ppid=%d,r11=%d\n",getpid(),getppid(),r11);
   
			
			exit(0);
		}	
	 }
	else
	{
		r2=fork();
		if(r2<0)
		{
			perror("fork2 failed!\n");
			exit(-1);
		}
		else if(r2==0)
		{
			int r21;
			r21=fork();
			if(r21<0)
			{
				perror("r21 fork failed!\n");
				exit(-1);
			}
			else if(r21==0)
			{
				printf("child21:pid=%d,ppid=%d\n",getpid(),getppid());
				exit(0);
			}
			else
			{
				wait(NULL);
				info(21,r21);
				printf("child2 :pid=%d,ppid=%d,r21=%d\n",getpid(),getppid(),r21);
				exit(0);
			}

		}
		
		else{
                        int s1,m1,s2,m2;
			m1=wait(&s1);
			m2=wait(&s2);
			if(m1==r1)
			{
				info(1,r1);
			}
			else
			{
				info(2,r2);
			}
			if(m2==r1)
			{
				info(1,r1);
			}
			else
			{
				info(2,r2);
			}
			
				printf("parent :pid=%d,r1=%d,r2=%d\n",getpid(),r1,r2);

				return 0;
		}
	}
}

