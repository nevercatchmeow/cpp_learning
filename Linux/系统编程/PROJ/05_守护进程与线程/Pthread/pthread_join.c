// Compile and link with -pthread.
// int pthread_join(); 阻塞等待线程结束。 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

static int count = 0;

void *myThread(void *args)
{
    int i = 0;
    int n = *(int *)args;
    for (i = 0; i <= n; i++)
    {
        count += i;
        printf("The myThread method count is = %d\n", count);
        // sleep(1);
    }
    pthread_exit(0);
}

int main()
{
    int t = 10000;
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, myThread, &t);
    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", getpid(), pthread_self());
    }

    pthread_join(tid, NULL);
    printf("The count is = %d\n", count);

    sleep(1);
    return 0;
}