#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    struct dirent *pDent = NULL;

    // DIR *opendir (const char *__name);
    DIR *pDir = opendir(argv[1]);
    if (pDir == NULL)
    {
        perror("opendir error");
        return -1;
    }

    
    while ((pDent = readdir(pDir)) != NULL)
    {
        if (strcmp(pDent->d_name, ".") == 0 || strcmp(pDent->d_name, "..") == 0)
        {
            continue;
        }

        printf("[%s]====>", pDent->d_name);

        switch (pDent->d_type)
        {
            case DT_REG:
                printf("普通文件");
                break;
            case DT_DIR:
                printf("目录文件");
                break;
            case DT_LNK:
                printf("链接文件");
                break;
            default:
                printf("未知文件");
        }

        printf("\n");
        
    }

    closedir(pDir);
    
    return 0;
}