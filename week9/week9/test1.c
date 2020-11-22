#include"./ch09.h"
int main()
{
 
 
printf("This is parent process%d\n",getpid()); 
pid_t p1,p2,p3,p4; 
if((p1=fork())==0)
{ 
printf("This is child_1 process%d\n",getpid());
if((p3=fork())==0)
{ 
printf("This is child_1-1 process%d\n",getpid()); 
}
else
{ 
if((p4=fork())==0)
{ 
printf("This is child_1-2 process%d\n",getpid()); 
}
else
{ 
waitpid(p3,NULL,0); 
waitpid(p4,NULL,0); 
printf("This is parent process%d\n",getpid()); 
} 
}

}
else
{ 
if((p2=fork())==0)
{ 
printf("This is child_2 process%d\n",getpid()); 
}
else
{ 
waitpid(p1,NULL,0); 
waitpid(p2,NULL,0); 
printf("This is parent process%d\n",getpid()); 
} 
} 
}
