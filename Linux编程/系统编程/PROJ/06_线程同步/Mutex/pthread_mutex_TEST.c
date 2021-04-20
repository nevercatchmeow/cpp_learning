#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// 1.创建互斥锁mutex（全局定义）
pthread_mutex_t mutex;

// 线程A处理函数
void *myThreadA(void *args)
{
    while (1)
    {
        // 3.临界区代码（加锁）
        pthread_mutex_lock(&mutex);

        printf("hello ");
        sleep(rand()%3);
        printf("hakuno\n");

        // 3.临界区代码（解锁）
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);
    }
    pthread_exit(NULL);
}

// 线程B处理函数
void *myThreadB(void *args)
{
    while (1)
    {
        // 3.临界区代码（加锁）
        pthread_mutex_lock(&mutex);
        
        printf("HELLO ");
        sleep(rand()%3);
        printf("HAKUNO\n");

        // 3.临界区代码（解锁）
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);
    }
    pthread_exit(NULL);
}

int main()
{
    // 2.初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    // 线程A
    pthread_t tid_A;
    int retA = pthread_create(&tid_A, NULL, myThreadA, NULL);
    if (retA != 0)
    {
        printf("pthread_create error, [%s]\n", getpid(), pthread_self());
    }
    // 线程B
    pthread_t tid_B;
    int retB = pthread_create(&tid_B, NULL, myThreadB, NULL);
    if (retB != 0)
    {
        printf("pthread_create error, [%s]\n", getpid(), pthread_self());
    }

    retA = pthread_join(tid_A, NULL);
	if(retA!=0)
	{
		printf("pthread_join error:[%s]\n", strerror(retA));
	}

    retB = pthread_join(tid_B, NULL);
	if(retB!=0)
	{
		printf("pthread_join error:[%s]\n", strerror(retB));
	}

    pthread_mutex_destroy(&mutex);

    return 0;
}