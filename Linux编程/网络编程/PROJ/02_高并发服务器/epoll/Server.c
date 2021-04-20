#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#include "../WRAP/wrap.h"

#define MAXLINE 256
#define SERV_PORT 8888
#define OPEN_MAX 1024 

int main()
{
    int i, j, maxi, listen_fd, connect_fd, sock_fd;
    int nready, efd, res;
    ssize_t n;
    char buf[MAXLINE], client_ip[INET_ADDRSTRLEN];
    socklen_t client_len;
    int client[OPEN_MAX];

    struct epoll_event tep, ep[OPEN_MAX];

    struct sockaddr_in server_addr, client_addr;
    bzero(&client_addr, sizeof(client_addr));
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    listen_fd = Socket(AF_INET, SOCK_STREAM, 0);
    Bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    Listen(listen_fd, 20);

    for (i = 0; i < OPEN_MAX; i++)
    {
        client[i] = -1;
    }
    maxi = -1;

    efd = epoll_create(OPEN_MAX);
    if (efd == -1)
    {
        perr_exit("epoll_create error");
    }


    

    return 0;
}