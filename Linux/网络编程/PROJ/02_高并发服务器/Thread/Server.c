#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "../WRAP/wrap.h"

#define MAXLINE 90
#define SERV_PORT 8888

struct s_info
{
    struct sockaddr_in client_addr;
    int fd;
};

void *do_work(void *args)
{
    int n,i;
    struct s_info *ts = (struct s_info*)args;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];

    pthread_detach(pthread_self());

    char client_ip[INET_ADDRSTRLEN];
    memset(client_ip, 0x00, sizeof(client_ip));
    printf("CLIENT %s:%d CONNECTED!\n", inet_ntop(AF_INET, &(*ts).client_addr.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs((*ts).client_addr.sin_port));

    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        n = Read(ts->fd, buf, MAXLINE);
        if (n <= 0)
        {
            printf("CLIENT %s:%d DISCONNECTED!\n", inet_ntop(AF_INET, &(*ts).client_addr.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs((*ts).client_addr.sin_port));
            break;
        }
        printf("RECV %s:%d:%s\n", inet_ntop(AF_INET, &(*ts).client_addr.sin_addr.s_addr, str, sizeof(str)), ntohs((*ts).client_addr.sin_port), buf);
        for (i = 0; i < n; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        Write(ts->fd, buf, n);
        printf("SEND %s:%d:%s\n", inet_ntop(AF_INET, &(*ts).client_addr.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs((*ts).client_addr.sin_port), buf);
    }
    Close(ts->fd);
}

int main()
{
    pthread_t tid;
    int i = 0;
    struct s_info ts[256];

    int listen_fd, connect_fd;
    struct sockaddr_in server_addr, client_addr;

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    socklen_t client_len;

    listen_fd = Socket(AF_INET, SOCK_STREAM, 0);
    Bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    Listen(listen_fd, 20);

    while (1)
    {
        client_len = sizeof(client_addr);
        connect_fd = Accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
        ts[i].client_addr = client_addr;
        ts[i].fd = connect_fd;

        pthread_create(&tid, NULL, do_work, (void*)&ts[i]);
        i++;
    }
    return 0;
}