#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("Before fork, pid:[%d]\n", getpid());
	//创建子进程
	//pid_t fork(void);
	pid_t pid = fork();
	if(pid < 0) //fork失败
	{
		perror("fork error");
		return -1;
	}
	else if(pid > 0)//父进程
	{
		printf("Father: 创建的子进程id==[%d], pid==[%d], fpid==[%d]\n", pid, getpid(),getppid());
		sleep(1);
	}
	else if(pid == 0) //子进程
	{
		printf("Child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
	}
	
	printf("After fork, pid:[%d]\n", getpid());

	return 0;
}
