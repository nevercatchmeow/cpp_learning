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
    int connect_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect_fd < 0)
    {
        perror("socket error");
        return -1;
    }

    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);
    socklen_t server_len = sizeof(server);
    int ret = connect(connect_fd, (struct sockaddr *)&server, server_len);
    if (ret < 0)
    {
        perror("connect error");
        return -1;
    }
    char server_ip[INET_ADDRSTRLEN];
    memset(server_ip, 0x00, sizeof(server_ip));
    printf("SERVER %s:%d CONNECTED!\n", inet_ntop(AF_INET, &server.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server.sin_port));

    int n = 0;
    char buf[256];

    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        n = read(STDIN_FILENO, buf, sizeof(buf));

        write(connect_fd, buf, n-1);
        
        memset(buf, 0x00, sizeof(buf));
        n = read(connect_fd, buf, sizeof(buf));
        if (n <= 0)
        {
            printf("SERVER %s:%d CLOSED!\n", inet_ntop(AF_INET, &server.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server.sin_port));
            break;
        }
        printf("RECEIVED DATA FROM %s:%d:%s\n", inet_ntop(AF_INET, &server.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server.sin_port), buf);
    }

    close(connect_fd);

    return 0;
}