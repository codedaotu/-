#include"head.h"
void sig_h1( int arg)
{
	printf("thread1 get singa\n");
	return;
}

void sig_h2( int arg)
{
	printf("thread2get singa\n");
	return;
}

void *thread_fun1(void * arg)
{

	printf("new thread1 start\n");
	struct sigaction act;
	memset(&act,0,sizeof(act));
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler = sig_h1;
	sigaction(SIGQUIT,&act,NULL);
	pthread_sigmask(SIG_BLOCK,&act.sa_mask,NULL);
	sleep(2);
}
void *thread_fun2(void * arg)
{

	printf("new thread2 start\n");
	struct sigaction act;
	memset(&act,0,sizeof(act));
	sigaddset(&act.sa_mask,SIGINT);
	act.sa_handler = sig_h2;
	sigaction(SIGINT,&act,NULL);
	//pthread_sigmask(SIG_BLOCK,&act.sa_mask,NULL);
	sleep(2);
}
int main()
{
 	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,thread_fun1,NULL);
	pthread_create(&tid2,NULL,thread_fun2,NULL);
	int s;
	sleep(1);
	s=pthread_kill(tid1,SIGQUIT);
	s=pthread_kill(tid2,SIGINT);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

}
