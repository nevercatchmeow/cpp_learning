#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

int main()
{
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
    {
        perror("socket error");
        return -1;
    }

    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    socklen_t server_len = sizeof(server);
    int ret = bind(listen_fd, (struct sockaddr *)&server, server_len);
    if (ret < 0)
    {
        perror("bind error");
        return -1;
    }
    
    listen(listen_fd, 128);

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int connect_fd = accept(listen_fd, (struct sockaddr *)&client, &client_len);
    if (connect_fd < 0)
    {
        perror("accept error");
        return -1;
    }

    char client_ip[16];
    memset(client_ip, 0x00, sizeof(client_ip));
    printf("CLIENT %s:%d CONNECTED!\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port));

    int i = 0;
    int n = 0;
    char buf[1024];

    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        n = read(connect_fd, buf, sizeof(buf));
        if (n <= 0)
        {
            printf("CLIENT %s:%d DISCONNECTED!\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port));
            break;
        }
        printf("RECEIVED DATA FROM %s:%d:%s\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port), buf);
        for (i = 0; i < n; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        write(connect_fd, buf, n);
        printf("SEND DATA TO %s:%d:%s\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port), buf);
    }

    close(connect_fd);
    close(listen_fd);

    return 0;
}