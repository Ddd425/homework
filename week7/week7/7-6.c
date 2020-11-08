#include"./ch07.h"
int main(int argc,char *argv[],char *env[])

{
	extern char** environ;
	int i;
	for(i=0;environ[i];i++)
		printf("env[%d]=%s\n",i,environ[i]);
	for(i=0;env[i]!=NULL;i++)
		printf("env[%d]=%s\n",i,env[i]);
	return 0;
} 

