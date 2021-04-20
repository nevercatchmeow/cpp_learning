// signal函数测试：注册信号处理函数。
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
    // while (1)
    {
        sleep(10);
    }

    return 0;
}