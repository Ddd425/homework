#include"../ch08.h"

void dynamic_lib_fun_call(void)
{
	printf("Dynamic lib fun called!\n");
}
void mysort(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
}
void myrand(int *a,int n)
{
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100+1;
	}
}
void pyprint(int *a,int n)
{
	for(int i=0;i<n;i++)
		printf("a[%d]=%d\n",i,a[i]);
}
