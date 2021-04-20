// sigaction函数：注册信号处理函数。
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

// 信号处理函数
void sigHandler(int sigNo)
{
    printf("sigNo==[%d]\n", sigNo);
    sleep(5);
}

int main()
{
    // 注册信号处理函数
    struct sigaction act;
    act.sa_handler= sigHandler;
    sigemptyset(&act.sa_mask);  // 信号处理函数执行期间，不阻塞任何信号。
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, NULL);      
    signal(SIGQUIT, sigHandler);

    while (1)
    {
        sleep(1);
    }

    return 0;
}