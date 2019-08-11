#include"head.h"
pid_t getpid(void);
int main()
{
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("pid is %u,tid is %lx",pid,tid);
	return 0;
}
