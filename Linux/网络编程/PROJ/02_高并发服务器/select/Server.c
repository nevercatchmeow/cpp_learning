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
    int i, maxi, maxfd, sock_fd, listen_fd, connect_fd;
    int nready;
    int client[FD_SETSIZE]; // FD_SETSIZE 默认为 1024
    
    ssize_t n;

    fd_set rset;
    fd_set allset;

    char buf[MAXLINE];
    char client_ip[INET_ADDRSTRLEN]; // #define INET_ADDRSTRLEN 16
    socklen_t client_len;
    struct sockaddr_in client_addr, server_addr;

    listen_fd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&client_addr, sizeof(client_addr));
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    Bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // listen()的参数backlog：未完成队列与已完成队列和的最大值，默认最大为128。
    Listen(listen_fd, 20);

    maxfd = listen_fd;  // 初始化
    maxi = -1; // client[]的下标

    for (i = 0; i < FD_SETSIZE; i++)
    {
        client[i] = -1; // 使用-1初始化client[]
    }
    FD_ZERO(&allset);
    FD_SET(listen_fd, &allset); // 构造select监控文件描述符集

    while (1)
    {
        rset = allset; // 每次循环时重新设置select监控集合
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);

        if (nready < 0)
            perr_exit("select error");
        if (FD_ISSET(listen_fd, &rset))
        {
            client_len = sizeof(client_addr);
            connect_fd = Accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);
            printf("CLIENT %s:%d CONNECTED!\n", inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, client_ip, sizeof(client_ip)), ntohs(client_addr.sin_port));
            for (i = 0; i < FD_SETSIZE; i++)
            {
                if (client[i] < 0)
                {
                    client[i] = connect_fd; // 保存accept返回的文件描述符到client[]中
                    break;
                }
            }
            // 达到select可监控的文件描述符个数上限1024
            if (i == FD_SETSIZE)
            {
                fputs("NOT CONNNECTABLE!\n", stderr);
                exit(1);
            }
            FD_SET(connect_fd, &allset); // 添加新的文件描述符到监控集合中
            if (connect_fd > maxfd)
                maxfd = connect_fd; // 更新maxfd，select函数需要
            if (i > maxi)
                maxi = i; // 更新client[]最大下标值
            if (--nready == 0)
                continue; // 如果未监听到就绪文件描述符则返回继续阻塞监听，否则处理未处理完的就绪文件描述符	    
        }

        for (i = 0; i <= maxi; i++) { // 遍历已连接套接字（轮询）
			if ( (sock_fd = client[i]) < 0)
				continue;
			if (FD_ISSET(sock_fd, &rset)) { // 判断该文件描述符是否就绪
                memset(&buf, 0x00, sizeof(buf));
                memset(&client_ip, 0x00, sizeof(client_ip));
				if ( (n = Read(sock_fd, buf, MAXLINE)) == 0) 
                {
					Close(sock_fd); // Client关闭连接时，服务端也关闭对应连接。
					FD_CLR(sock_fd, &allset); // 解除对该文件描述符的监听。
					client[i] = -1;
				} 
                else 
                {
                    printf("RECV:%s\n", buf);
                    
					int j;
					for (j = 0; j < n; j++)
						buf[j] = toupper(buf[j]);
					Write(sock_fd, buf, n);
                    printf("SEND:%s\n", buf);
                    memset(&buf, 0x00, sizeof(buf));
                    memset(&client_ip, 0x00, sizeof(client_ip));
				}
				if (--nready == 0)
					break;
			}
		}
    }
    
    close(listen_fd);
	return 0;
}