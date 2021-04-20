// setitimer：定时器
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

// 信号处理函数
void signalHandler(int sigNo)
{
    switch (sigNo)
    {
        case SIGALRM:
            printf("Caught the SIGALRM signal!\n");
            break;
    }
}

int main()
{
    signal(SIGALRM, signalHandler);

    // 五秒后开始，每500ms（500000us）循环一次。
    struct itimerval new_value, old_value;
    new_value.it_value.tv_sec = 5;
    new_value.it_value.tv_usec = 0;
    new_value.it_interval.tv_sec = 0;
    new_value.it_interval.tv_usec = 500000;
    setitimer(ITIMER_REAL, &new_value, &old_value);
    
    while (1)
    {
        /* code */
    }

	return 0;
}