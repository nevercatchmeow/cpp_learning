// kill函数：向指定进程发送指定信号。
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

    while (1)
    {
        sleep(1);
        kill(getpid(), SIGINT);
    }

    return 0;
}