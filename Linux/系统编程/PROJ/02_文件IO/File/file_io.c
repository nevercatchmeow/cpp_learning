//IO函数测试：open()、close()、read()、write()、lseek()
#include <stdio.h>
#include <stdlib.h>

// memset()
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

// lseek()、close()、read()、write()
#include <unistd.h>
// open()
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char read_buf[1024];

	int fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, 0777);
	if(fd<0)
	{
		perror("open error");
		return -1;
	}

	//ssize_t write(int fd, const void *buf, size_t count);
	write(fd, " Hakuno", strlen(" Hakuno"));

	lseek(fd, 0, SEEK_SET);

	//ssize_t read(int fd, void *buf, size_t count);

	memset(read_buf, 0x00, sizeof(read_buf));

	int n = read(fd, read_buf, sizeof(read_buf));
	printf("n==[%d], buf==[%s]\n", n, read_buf);

	close(fd);

	return 0;
}
