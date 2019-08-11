#include"head.h"
typedef struct 
{
	int age;
	char name[20];
}student;
void *thread_fun(void* stu)
{
	sleep(2);
	printf("age is %d,name is %s\n",((student *)stu)->age,((student *)stu)->name);
	return (void*)0;
}
int main(int argc,char *argv[])
{
	pthread_t tid;
	int err;
	student stu;
	stu.age=20;
	int *val;
	memcpy(stu.name,"一只王八",20);
	err = pthread_create(&tid,NULL,thread_fun,(void*)(&stu));
	if(err!=0)
	{
		printf("create thread failed\n");
		return 0;
	}
	int i;
	printf("main thread have %d args\n",argc);
	for(int i=0;i<argc;i++)
	{
		printf("main arg is %s\n",argv[i]);
	}
	pthread_exit(val);

}
