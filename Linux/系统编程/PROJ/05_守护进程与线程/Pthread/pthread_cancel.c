// Compile and link with -pthread.
// int pthread_cancel(); 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

//线程执行函数
void *mythread(void *arg)
{
	while(1)
	{
		int a;
		int b;

		//设置取消点
		pthread_testcancel();

		printf("-----\n");
	}
}

int main()
{
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, mythread, NULL);
	if(ret!=0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		return -1;
	}
	printf("main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());

	pthread_cancel(tid);

	pthread_join(tid, NULL);
	return 0;
}