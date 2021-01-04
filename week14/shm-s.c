#include"ch14.h"
int main()
{
	char c,*shm,*s;
	int shmid;
	if((shmid=shmget(758,SHMSZ,IPC_CREAT|0666))<0)
		err_exit("shmget failed!\n");
	if((shm=shmat(shmid,NULL,0))==(char *)-1)
		err_exit("shmat!\n");
	s=shm;
	for(c='a';c<='z';c++)
		*s++=c;
	*s='\0';
	exit(0);
}
