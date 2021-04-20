// stat函数测试：获取文件大小、文件所有者、文件所有者所属组、文件类型与权限。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    // int stat (const char *pathname, struct stat *buf);
    // int lstat (const char *pathname, struct stat *buf);
    // 区别：对于连接文件，lstat获取链接文件本身的属性信息，stat获取链接指向的文件信息。
    struct stat sb;
    // 获取文件属性
    printf("== 文件名称：%s\n", argv[1]);
    stat(argv[1], &sb);

    printf("== 文件大小：%d\n", sb.st_size);
    printf("== 文件属主：%d\n", sb.st_uid);
    printf("== 文件属组：%d\n", sb.st_gid);

    // 获取文件类型
    printf("== 文件类型：");
    if (S_ISREG(sb.st_mode))
    {
        printf("普通文件。\n");
    }
    else if (S_ISDIR(sb.st_mode))
    {
        printf("目录文件。\n");
    }
    else if (S_ISLNK(sb.st_mode))
    {
        printf("链接文件。\n");
    }

    // 判断文件权限
    printf("== 文件权限：");
    if (sb.st_mode & S_IROTH)
    {
        printf("R ");
    }

    if (sb.st_mode & S_IWOTH)
    {
        printf("W ");
    }

    if (sb.st_mode & S_IXOTH)
    {
        printf("X ");
    }
    
    printf("\n");

    return 0;
}