// dup函数测试：
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
    int old_fd = open(argv[1], O_RDWR|O_APPEND);
    if(old_fd < 0)
    {
        perror("open error");
        return -1;
    }

    // dup()
    int new_fd = dup(old_fd);
    printf("old_fd = %d\n", old_fd);
    printf("new_fd = %d\n", new_fd);

    // write()
    write(new_fd, " function: dup() ", strlen(" function: dup() "));

    // read()
    lseek(old_fd, 0, SEEK_SET); 
    char buf[1024];
    memset(buf, 0x00, sizeof(buf));
    int n = read(new_fd, buf, sizeof(buf));
    printf("read over: n = [%d], buf = [%s]\n", n, buf);

    // close
    close(old_fd);
    close(new_fd);
    
    return 0;
}