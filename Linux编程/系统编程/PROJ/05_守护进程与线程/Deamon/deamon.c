// 创建守护进程：每2s获取一次系统时间，并写入文件。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>

void myFunc(int sigNo)
{
    int fd = open("mydemon.log", O_RDWR|O_CREAT|O_APPEND, 0644);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    time_t t;
    time(&t);   // 将当前时间填入t。
    char *p = ctime(&t);

    write(fd, p, strlen(p));
    close(fd);

    return;
}

int main()
{
    // 创建子进程、退出父进程
    pid_t pid = fork();
    if (pid < 0 | pid > 0)
    {
        exit(1);
    }
    // 子进程创建会话
    setsid();
    // 改变工作目录
    chdir("/home/hakuno/log");
    // 改变文件掩码
    umask(0000);
    // 关闭标准输入、输出和错误输出文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    // 注册信号处理函数
    struct sigaction act;
    act.sa_handler = myFunc;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);
    // 设置时钟
    struct itimerval tm;
    tm.it_interval.tv_sec = 2;
    tm.it_interval.tv_usec = 0;
    tm.it_value.tv_sec = 2;
    tm.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &tm, NULL);

    printf("TAT\n");

    while (1)
    {
        sleep(1);
    }
    
}