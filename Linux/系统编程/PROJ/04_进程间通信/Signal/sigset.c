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
    signal(SIGQUIT, signalHandler);

    // 定义sigset_t类型的变量
    sigset_t pending, mask, oldmask;

    // 初始化
    sigemptyset(&pending);
    sigemptyset(&mask);
    sigemptyset(&oldmask);

    // 将SIGINT和SIGQUIT加入到自定义mask信号集中
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);

    // 将mask中的SIGINT和SIGQUIT信号加入到阻塞信号集中
    sigprocmask(SIG_BLOCK, &mask, &oldmask);

    int i = 1;
    int k = 1;
    while (1)
    {
        // 获取未决信号集
        sigpending(&pending);

        for (i = 1; i < 32; i++)
        {
            // 判断某个信号是否在信号集中
            if (sigismember(&pending, i)==1)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
        
        if (k++%10==0)
        {
            // 从阻塞信号集中解除对SIGINT和SIGQUIT的阻塞
            sigprocmask(SIG_SETMASK, &oldmask, NULL);
        }
        else
        {
            sigprocmask(SIG_BLOCK, &mask, NULL);
        }

        sleep(1);
    }
    
    return 0;
}