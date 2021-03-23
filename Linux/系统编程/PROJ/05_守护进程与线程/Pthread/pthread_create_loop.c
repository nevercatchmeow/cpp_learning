// Compile and link with -pthread.
// int pthread_create(); 打印线程序号
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *myThread(void *args)
{
    int i = *(int *)args;
    printf("[%d]:Child thread, pid==[%d], id==[%ld]\n", i, getpid(), pthread_self());
}

int main()
{
    int i = 0;
    int n = 5;
    int arr[5];
    pthread_t thread[5];

    for (i = 0; i < n; i++)
    {
        arr[i] = i;
        int ret = pthread_create(&thread[i], NULL, myThread, &arr[i]);
        if (ret != 0)
        {
            printf("pthread_create error, [%s]\n", getpid(), pthread_self());
            return -1;
        }
    }
    printf("Main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());

    sleep(1);
    return 0;
}