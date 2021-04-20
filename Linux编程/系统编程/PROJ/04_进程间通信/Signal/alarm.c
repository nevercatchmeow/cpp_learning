// alarm函数：设置定时器。
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

// 信号处理函数
void signalHandler(int sigNo)
{
    printf("sigNum == [%d]\n", sigNo);
}

int main()
{
    // 注册信号处理函数
    signal(SIGINT, signalHandler);
    signal(SIGALRM, signalHandler);

    int n = alarm(5);
    printf("first: n==[%d]\n", n);

    sleep(2);
    n = alarm(5);
    // n = alarm(0); // 取消时钟
    printf("second: n==[%d]\n", n);

    while (1)
    {
        sleep(1);
    }

    return 0;
}