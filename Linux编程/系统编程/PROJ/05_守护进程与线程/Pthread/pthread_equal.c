// Compile and link with -pthread.
// int pthread_cancel(); 比较线程ID是否相等
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *myThread(void *arg)
{
	printf("child thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());
}

int main()
{
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, myThread, NULL);
	if(ret!=0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		return -1;
	}
	printf("main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());
    
    // if(pthread_equal(thread, pthread_self())!=0)
	if(pthread_equal(pthread_self(), pthread_self())!=0)
	{
		printf("two thread id is same\n");
	}
	else
	{
		printf("two thread id is not same\n");
	}

	sleep(1);
	return 0;
}