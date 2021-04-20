#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "../WRAP/wrap.h"

#define MAXLINE 256
#define SERV_PORT 8888

int main()
{
    int connect_fd = Socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr);
    socklen_t server_len = sizeof(server_addr);

    Connect(connect_fd, (struct sockaddr *)&server_addr, server_len);

    char server_ip[INET_ADDRSTRLEN];
    memset(server_ip, 0x00, sizeof(server_ip));
    printf("SERVER %s:%d CONNECTED!\n", inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server_addr.sin_port));

    int n = 0;
    char buf[MAXLINE];
    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        n = Read(STDIN_FILENO, buf, sizeof(buf));

        Write(connect_fd, buf, n-1);
        
        memset(buf, 0x00, sizeof(buf));
        n = Read(connect_fd, buf, sizeof(buf));
        if (n <= 0)
        {
            printf("SERVER %s:%d CLOSED!\n", inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server_addr.sin_port));
            break;
        }
        printf("RECV %s:%d:%s\n", inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server_addr.sin_port), buf);
    }

    Close(connect_fd);

    return 0;
}