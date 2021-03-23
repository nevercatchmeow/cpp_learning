#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
		printf("Father: 创建的子进程id==[%d], pid==[%d], fpid==[%d]\n", pid, getpid(),getppid());
    }
    else if (pid == 0)
    {
        printf("Child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
        // execl("/bin/ls", "ls", "-1", NULL);
        execlp("./fork", "fork", NULL);
    }
    
    return 0;
}