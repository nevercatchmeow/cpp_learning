// Compile and link with -pthread.
// int pthread_detach(); 线程分离状态
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *myThread(void *args)
{
    printf("Child thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());
    sleep(1);
}

int main()
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, myThread, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", getpid(), pthread_self());
        return -1;
    }
    printf("Main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());

    pthread_detach(tid);

    // 已完成线程分离，pthread_join将失败
	ret = pthread_join(tid, NULL);
	if(ret!=0)
	{
		printf("pthread_join error:[%s]\n", strerror(ret));
	}

    sleep(1);
    return 0;
}