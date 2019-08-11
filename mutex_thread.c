#include"head.h"
int n=0;
pthread_mutex_t mutex;
pthread_cond_t odd;
pthread_cond_t even;
void print_odd()
{
	pthread_mutex_lock(&mutex);
	if(n%2==0)
	{
		printf("wait for odd\n");
		pthread_cond_wait(&odd,&mutex);
	}	
	printf("%d is odd\n",n);
	pthread_cond_signal(&even);
	pthread_mutex_unlock(&mutex);
}
void print_even()
{
	pthread_mutex_lock(&mutex);
	if(n%2==1)
	{
		printf("wait for even\n");
		pthread_cond_wait(&even,&mutex);
	}	
	printf("%d is even\n",n);
	pthread_cond_signal(&odd);
	pthread_mutex_unlock(&mutex); 
}

void *thread_fun1( void *arg)
{
	while(n<1000)
	{	
		print_odd();
		n++;
	}
	return (void *)0;
}
void *thread_fun2( void *arg)
{	while(n<1000)
	{
		print_even();
		n++;

	}
	return (void *)0;
}

int main()
{

	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&odd,NULL);
	pthread_cond_init(&even,NULL); 
	pthread_t tid2,tid1;
	pthread_create(&tid2,NULL,thread_fun2,NULL);	
	pthread_create(&tid1,NULL,thread_fun1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid1,NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&even);
	pthread_cond_destroy(&odd);
	return 0;

}
