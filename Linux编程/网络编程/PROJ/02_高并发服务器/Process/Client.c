#include "../WRAP/wrap.h"

int main()
{
    int connect_fd = Socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);
    socklen_t server_len = sizeof(server);

    Connect(connect_fd, (struct sockaddr *)&server, server_len);

    char server_ip[INET_ADDRSTRLEN];
    memset(server_ip, 0x00, sizeof(server_ip));
    printf("SERVER %s:%d CONNECTED!\n", inet_ntop(AF_INET, &server.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server.sin_port));

    int n = 0;
    char buf[256];
    while (1)
    {
        memset(buf, 0x00, sizeof(buf));
        n = Read(STDIN_FILENO, buf, sizeof(buf));

        Write(connect_fd, buf, n-1);
        
        memset(buf, 0x00, sizeof(buf));
        n = Read(connect_fd, buf, sizeof(buf));
        if (n <= 0)
        {
            printf("SERVER %s:%d CLOSED!\n", inet_ntop(AF_INET, &server.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server.sin_port));
            break;
        }
        printf("RECV %s:%d:%s\n", inet_ntop(AF_INET, &server.sin_addr.s_addr, server_ip, sizeof(server_ip)), ntohs(server.sin_port), buf);
    }

    Close(connect_fd);

    return 0;
}