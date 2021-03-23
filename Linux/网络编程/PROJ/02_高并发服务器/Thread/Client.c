#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "../WRAP/wrap.h"

#define MAXLINE 90
#define SERV_PORT 8888

int main()
{   
    struct sockaddr_in server_addr;
    char buf[MAXLINE];
    int fd, n;

    fd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    server_addr.sin_port = htons(SERV_PORT);

	Connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char server_ip[INET_ADDRSTRLEN];
    memset(server_ip, 0x00, sizeof(server_ip));
    printf("SERVER %s:%d CONNECTED!\n", inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server_addr.sin_port));

    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        n = Read(STDIN_FILENO, buf, sizeof(buf));

        Write(fd, buf, n-1);
        
        memset(buf, 0x00, sizeof(buf));
        n = Read(fd, buf, sizeof(buf));
        if (n <= 0)
        {
            printf("SERVER %s:%d CLOSED!\n", inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server_addr.sin_port));
            break;
        }
        printf("RECV %s:%d:%s\n", inet_ntop(AF_INET, &server_addr.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server_addr.sin_port), buf);
    }
	Close(fd);
    return 0;
}