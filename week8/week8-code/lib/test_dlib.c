#include"../ch08.h"
extern void dynamic_lib_fun_call(void);
extern void mysort(int *a,int n);
extern void myrand(int *a,int n);

extern void pyprint(int *a,int n);
int main(void)

{
	int a[10]={0};
	dynamic_lib_fun_call();
	printf("---init----\n");
	pyprint(a,10);
	sleep(5);
	myrand(a,10);
	printf("---Rand----\n");
	pyprint(a,10);
	sleep(5);
	printf("----SORT----\n");
	mysort(a,10);
	pyprint(a,10);
	return 0;
}

