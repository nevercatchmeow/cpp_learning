#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int ret = access("./myfifo", F_OK);
    if (ret != 0)
    {
        ret = mkfifo("./myfifo", 0777);
        if (ret < 0)
        {
            perror("mkfifo error");
            return -1;
        }
    }

    int fd = open("./myfifo", O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return -1;
    }
    
    int n = 0;
    char buf[64];
    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        n = read(fd, buf, sizeof(buf));
        printf("n==[%d], buf==[%s]\n", n, buf);
    }

    close(fd);

    return 0;
}