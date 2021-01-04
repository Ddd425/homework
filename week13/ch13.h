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

#define SERVER_FIFO_NAME"./server_fifo"
#define CLIENT_FIFO_NAME"./client_%d_fifo"
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



void err_exit(char *s)
{
	printf("Usage: %s is faile!\n",s);
	exit(0);
}
