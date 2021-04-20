// Compile and link with -pthread.
// int pthread_create(); 传递结构体参数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

struct Test
{
    int data;
    char name[64];
};

void *myThread(void *args)
{
    struct Test *p = (struct Test *)args;
    printf("[%d][%s]\n", p->data, p->name);
    printf("Child thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());
}

int main()
{
    struct Test t;
    memset(&t, 0x00, sizeof(struct Test));
    t.data = 19;
    strcpy(t.name, "hakuno");

    pthread_t thread;
    int ret = pthread_create(&thread, NULL, myThread, &t);
    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", getpid(), pthread_self());
    }

    printf("Main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());

    sleep(1);
    return 0;
}