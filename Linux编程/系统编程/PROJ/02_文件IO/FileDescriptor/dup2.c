// dup2函数测试：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    // open
    int fd_1 = open(argv[1], O_RDWR|O_APPEND);
    if(fd_1 < 0)
    {
        perror("open error");
        return -1;
    }

    int fd_2 = open(argv[2], O_RDWR|O_APPEND);
    if(fd_2 < 0)
    {
        perror("open error");
        return -1;
    }

    // dup2
    dup2(fd_1, fd_2);
    printf("fd_1 = %d\n", fd_1);
    printf("fd_2 = %d\n", fd_2);

    // write()
    write(fd_2, " function: dup2() ", strlen(" function: dup2() "));

    // read()
    lseek(fd_2, 0, SEEK_SET); 
    char buf[1024];
    memset(buf, 0x00, sizeof(buf));
    int n = read(fd_2, buf, sizeof(buf));
    printf("read over: n = [%d], buf = [%s]\n", n, buf);

    // close
    close(fd_2);
    close(fd_1);

    return 0;
}