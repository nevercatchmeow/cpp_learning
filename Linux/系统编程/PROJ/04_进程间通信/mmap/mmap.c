// 使用mmap函数完成父子进程间通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	// 使用mmap函数建立共享映射区
	int fd = open("./test.log", O_RDWR);
	if(fd < 0)
	{
		perror("open error");
		return -1;
	}

	int len = lseek(fd, 0, SEEK_END);

	void * addr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr==MAP_FAILED)
	{
		perror("mmap error");
		return -1;
	}
	close(fd);

	// 创建子进程
	pid_t pid = fork();
	if(pid < 0) 
	{
		perror("fork error");
		return -1;
	}
	else if(pid > 0)
	{
		memcpy(addr, "hello mmap", strlen("hello mmap"));	
		wait(NULL);
	}
	else if(pid == 0)
	{
		sleep(1);
		char *p = (char *)addr;
		printf("[%s]", p);
	}

    // munmap函数：释放存储映射区。
    // int munmap (void *__addr, size_t __len) __THROW;

	return 0;
}