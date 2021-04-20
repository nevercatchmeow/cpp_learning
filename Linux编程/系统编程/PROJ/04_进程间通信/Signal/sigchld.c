// 父进程使用SICCHLD信号完成对子进程的回收
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void waitChild(int sigNo)
{
    pid_t wpid;
    // 回收子进程（SIGCHLD被阻塞，产生多个但只处理一个，故使用while(1)回收多个子进程）
    while (1)
    {
        wpid = waitpid(-1, NULL, WNOHANG);
        if (wpid > 0)
        {
            printf("Child is quit, wpid==[%d]\n", wpid);
        }
        else if (wpid == 0)
        {
            printf("Child is living, wpid==[%d]\n", wpid);\
            break;
        }
        else if (wpid == -1)
        {
            printf("no child is living, wpid==[%d]\n", wpid);
            break;
        }
    }
}

int main()
{
    int i = 0;
    int n = 3;
    // 将SIGCHLD信号阻塞（避免子进程在信号处理函数注册前退出）
    __sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    for (i = 0; i < n; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        { 
            perror("fork error");
            return -1;
        }
        else if (pid > 0)
        {
            printf("Father: fpid==[%d], cpid==[%d]\n", getpid(), pid);
            sleep(1);
        }
        else if (pid == 0)
        {
            printf("Child: fpid==[%d], cpid==[%d]\n", getppid(), getpid());
            break;
        }
    }
    // 父进程
	if(i==3)
	{
		printf("[%d]:Father: fpid==[%d]\n", i, getpid());
		//signal(SIGCHLD, waitchild);
		//注册信号处理函数
		struct sigaction act;
		act.sa_handler = waitChild;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sleep(5);
		sigaction(SIGCHLD, &act, NULL);

		//解除对SIGCHLD信号的阻塞
		sigprocmask(SIG_UNBLOCK, &mask, NULL);

		while(1)
		{
			sleep(5);
            printf("Current process's pid==[%d]\n", getpid());
		}
	}

    // 第1个子进程
	if(i==0)
	{
		printf("[%d]:Child: cpid==[%d]\n", i, getpid());
		sleep(1);
	}

	// 第2个子进程
	if(i==1)
	{
		printf("[%d]:Child: cpid==[%d]\n", i, getpid());
		sleep(1);
	}

	// 第3个子进程
	if(i==2)
	{
		printf("[%d]:Child: cpid==[%d]\n", i, getpid());
		sleep(1);
	}
    
    return 0;
}