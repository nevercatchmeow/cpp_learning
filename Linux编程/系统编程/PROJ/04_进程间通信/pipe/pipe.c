#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // 创建管道
    int fd[2];
    int ret = pipe(fd);
    printf("pipe size==[%ld]\n", fpathconf(fd[0], _PC_PIPE_BUF));
    printf("pipe size==[%ld]\n", fpathconf(fd[1], _PC_PIPE_BUF));

    if (ret < 0)
    {
        perror("pipe error.");
        return -1;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0)        // fork失败
    {
        perror("fork error.");
        return -1;
    }
    else if (pid > 0)   // 父进程
    {
        // 关闭读端
        close(fd[0]);
        sleep(5);
        write(fd[1], "hello pipo", strlen("hello pipo"));
    }
    else                // 子进程
    {
        // 关闭写端
        close(fd[1]);
        char buf[64];
        memset(buf, 0x00, sizeof(buf));
        int n = read(fd[0], buf, sizeof(buf));
        printf("read over, n==[%d], buf==[%s]\n", n, buf);
    }
    
    return 0;
}