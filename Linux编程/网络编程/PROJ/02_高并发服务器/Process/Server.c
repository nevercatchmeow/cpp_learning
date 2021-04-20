#include "../WRAP/wrap.h"

int main()
{
    int listen_fd = Socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    socklen_t server_len = sizeof(server);

    Bind(listen_fd, (struct sockaddr *)&server, server_len);

    Listen(listen_fd, 1024);

    pid_t pid;
    int connect_fd;
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    socklen_t client_len = sizeof(client);

    while (1)
    {
        connect_fd = Accept(listen_fd, (struct sockaddr *)&client, &(client_len));
        char client_ip[INET_ADDRSTRLEN];
        memset(client_ip, 0x00, sizeof(client_ip));
        printf("CLIENT %s:%d CONNECTED!\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port));

        pid = fork();
        if (pid < 0)
        {
            perr_exit("fork error");
        }
        else if (pid > 0)
        {
            Close(connect_fd);
        }
        else if (pid == 0)
        {
            Close(listen_fd);

            int i=0;
			int n;
			char buf[1024];
			
			while(1)
			{
                memset(buf, 0x00, sizeof(buf));
				n = Read(connect_fd, buf, sizeof(buf));
				if(n<=0)
				{
                    printf("CLIENT %s:%d DISCONNECTED!\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port));
					break;
				}
				printf("RECV %s:%d:%s\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port), buf);
				
				for(i=0; i<n; i++)
				{
					buf[i] = toupper(buf[i]);
				}
				Write(connect_fd, buf, n);
                printf("SEND %s:%d:%s\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client.sin_port), buf);
			}
            Close(connect_fd);
            exit(0);
        }
    }

    Close(listen_fd);
    
    return 0;
}