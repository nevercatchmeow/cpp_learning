#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

static int number;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *myThreadA(void *args)
{
    int i = 0;
    int cur = 0;
    for (i = 0; i < 5000; i++)
    {
        pthread_mutex_lock(&mutex);

        cur = number;
        cur++;
        number = cur;
        printf("[A]:[%d]\n", number);

        pthread_mutex_unlock(&mutex);

        usleep(2);
    }
}

void *myThreadB(void *args)
{
    int i = 0;
    int cur = 0;
    for (i = 0; i < 5000; i++)
    {
        pthread_mutex_lock(&mutex);

        cur = number;
        cur++;
        number = cur;
        printf("[B]:[%d]\n", number);

        pthread_mutex_unlock(&mutex);

        usleep(2);
    }
}

int main()
{
    // pthread_mutex_t mutex;
    // pthread_mutex_init(&mutex, NULL);

    pthread_t tid_A;
    int retA = pthread_create(&tid_A, NULL, myThreadA, NULL);
    if (retA != 0)
    {
        printf("pthread_create error, [%s]\n", getpid(), pthread_self());
    }

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

    printf("number==[%d]\n", number);

    sleep(1);
    return 0;
}