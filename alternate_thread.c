#include"head.h"
void *thread_fun(void *t)

{
	
	for(int i=1;i<200;i+=2)
	{
		sleep(1);
		printf("sub_thread %d\n",i);
	}
	return (void*)0;
}
int main()
{

	int n=0;
	pthread_t tid;
	int err;
	err = pthread_create(&tid,NULL,thread_fun,(void *)&n);	
	if(err!=0)
	{
		printf("create thread failed\n");
		return 0;
	}
	while(n<100){
		printf("main_thread %d\n",n);
	n+=2;
	sleep(1);
	}
}

