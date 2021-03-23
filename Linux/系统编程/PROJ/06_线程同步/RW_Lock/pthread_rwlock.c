// 创建8个子线程：3读、5写。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

int number = 0;

// 定义读写锁
pthread_rwlock_t rwlock;

// 写线程回调函数
void *thread_write(void *arg)
{
    int i = *(int *)arg;
    int cur;
    while (1)
    {
        pthread_rwlock_wrlock(&rwlock);
        cur = number;
        cur++;
        number = cur;
        printf("[%d]-W:[%d]\n", i, cur);
        pthread_rwlock_unlock(&rwlock);
        sleep(rand()%3);
    }   
}
// 读线程回调函数
void *thread_read(void *arg)
{
    int i = *(int *)arg;
    int cur;
    while (1)
    {
        pthread_rwlock_rdlock(&rwlock);
        cur = number;
        printf("[%d]-R:[%d]\n", i, cur);
        pthread_rwlock_unlock(&rwlock);
        sleep(rand()%3);
    }   
}

int main()
{
    int n = 8;
    int i = 0;
    int arr[8];   
    pthread_t thread[8];

    // 读写锁初始化
    pthread_rwlock_init(&rwlock, NULL);

    // 创建3个写子线程
    for (i = 0; i < 3; i++)
    {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_write, &arr[i]);
    }

    // 创建5个读子线程
    for (i = 0; i < n; i++)
    {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_read, &arr[i]);
    }

    // 回收线程
    for (i = 0; i < n; i++)
    {
        pthread_join(thread[i], NULL);
    }

    // 释放锁
    pthread_rwlock_destroy(&rwlock);
    
    return 0;
}