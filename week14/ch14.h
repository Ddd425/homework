#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<setjmp.h>
#include<errno.h>
#include<wait.h>
#include<dlfcn.h>
#include<ctype.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#define SHMSZ 27

#define BUFFER_SIZE 132

#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024

#define PIPE_BUF 100
#define FIFO_FILE "./testfifo"
#define TEN_MEG 1000
#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH
struct data_to_pass{
	pid_t client_pid;
	char data[BUFFER_SIZE];
};

struct my_msg{
	long int my_msg_type;
	char text[BUFSIZ];
};

void err_exit(char *s)
{
	printf("Usage: %s is faile!\n",s);
	exit(0);
}
