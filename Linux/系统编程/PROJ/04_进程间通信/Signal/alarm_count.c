// 统计一秒钟计数：627665
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	alarm(1);
	int i = 0;
	while(1)
	{
		printf("[%d]\n", i++);
	}

	return 0;
}
