#include"ch11.h"
int main()
{
	FILE *fp;
	char *s="Hello World!\n";
	if((fp=fopen("./log.dat","w+"))==NULL)
	{
		printf("Error to create file!\n");
		exit(1);
	}
	fwrite(s,sizeof(char),strlen(s),fp);
	printf("After write\n");
	return 0;
}
