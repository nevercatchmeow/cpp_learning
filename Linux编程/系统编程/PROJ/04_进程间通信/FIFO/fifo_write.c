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
    
    int i = 0;
    char buf[64];
    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        sprintf(buf, "%d:%s", i, "hello fifo");
        write(fd, buf, strlen(buf));
        sleep(1);
        i++;
    }

    close(fd);

    return 0;
}