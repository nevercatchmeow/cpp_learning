// 使用条件变量实现生产者与消费者模型
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *head = NULL;
// 互斥锁
pthread_mutex_t mutex;
// 条件变量
pthread_cond_t cond;
// 生产者线程
void *producer(void *arg)
{
    NODE *pNode = NULL;
    while (1)
    {
        // 生产一个节点
        pNode = (NODE*)malloc(sizeof(NODE));
        if (pNode == NULL)
        {
            perror("malloc error");
            exit(1);
        }
        pNode->data = rand()%1000;
        printf("P:[%d]\n", pNode->data);
        // 加锁
        pthread_mutex_lock(&mutex);
        pNode->next = head;
        head = pNode;
        // 解锁
        pthread_mutex_unlock(&mutex);
        // 通知消费者线程解除阻塞
        pthread_cond_signal(&cond);
        sleep(rand()%3);
    }
    
}

void *consumer(void *arg)
{
    NODE *pNode = NULL;
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);

        if (head == NULL)
        {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("C:[%d]\n", head->data);
        pNode = head;
        head = head->next;

        // 解锁
        pthread_mutex_unlock(&mutex);
        free(pNode);
        pNode = NULL;

        sleep(rand()%3);
    }
}

int main()
{
    int ret;
    pthread_t thread1;
    pthread_t thread2;

    // 初始化互斥锁
    pthread_mutex_init(&mutex, NULL);
    // 初始化条件变量
    pthread_cond_init(&cond, NULL);
    // 创建生产者线程
    ret = pthread_create(&thread1, NULL, producer, NULL);
    if (ret != 0)
    {
        printf("pthread_creat error, [%s]\n", strerror(ret));
        return -1;
    }
    // 创建消费者线程
    ret = pthread_create(&thread2, NULL, consumer, NULL);
    if (ret != 0)
    {
        printf("pthread_creat error, [%s]\n", strerror(ret));
        return -1;
    }
    // 等待线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // 释放互斥锁
    pthread_mutex_destroy(&mutex);
    // 释放条件变量
    pthread_cond_destroy(&cond);

    return 0;
}