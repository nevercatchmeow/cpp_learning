#ifndef __WRAP_H_
#define __WRAP_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void perr_exit(const char *s);
int Socket(int family, int type, int protocol);
int Bind(int fd, const struct sockaddr *sa, socklen_t salen);
int Listen(int fd, int backlog);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
int Connect(int fd, struct sockaddr *sa, socklen_t salen);
int Close(int fd);

ssize_t Read(int fd, void *ptr, size_t nbytes);
ssize_t Write(int fd, const void *ptr, size_t nbytes);
ssize_t Readn(int fd, void *vptr, size_t n);
ssize_t Writen(int fd, const void *vptr, size_t n);
static ssize_t my_read(int fd, char *ptr);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
int tcp4bind(short port,const char *IP);

#endif // !__WRAP_H_