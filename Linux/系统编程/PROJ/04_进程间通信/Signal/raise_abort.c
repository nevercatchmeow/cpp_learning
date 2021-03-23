// raise函数：向当前进程发送指定信号。
// abort函数：向当前进程发送异常终止信号 6)SIGABRT 。
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

    // 向当前进程发送SIGINT信号
    raise(SIGINT);

    // 向当前进程发送SIGABRT信号
    abort();

    while (1)
    {
        sleep(1);
    }

    return 0;
}