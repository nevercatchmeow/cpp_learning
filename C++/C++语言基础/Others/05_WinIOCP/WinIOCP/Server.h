#pragma once

#ifndef WIN_IOCP_SERVER_H
#define WIN_IOCP_SERVER_H
#ifndef UNICODE
#define UNICODE
#endif // !UNICODE
#define WIN32_LEAN_AND_MEAN // 非MFC程序，加速生成过程

#include <iostream>
#include <cstdio>
#include <functional> // 回调
#include <vector>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <MSWSock.h>


#include "ServerSocket.h"

class Server
{
public:
	Server(u_short port); // 构造：传入端口号
	~Server(); // 析构
	bool startAccept(); // 
	void waitingForAccept(); //
	void waitingForIO(); // 
	bool isRunning() const { return m_running; } // 
	void stop() { m_running = false; } // 

	// 回调方式（代替虚函数）
	typedef std::function<void(ServerSocket::pointer)> HandleNewConnect;
	HandleNewConnect newConn;
	ServerSocket::HandleRecvFunction socketRecv;
	ServerSocket::HandleClose socketClose;
	ServerSocket::HandleError socketError;

private:
	bool m_running;
	u_short m_port; // 端口号
	std::vector<char> m_acceptBuffer; // 接收缓存区
	SOCKET m_listenSocket; // 监听Socket
	SOCKET m_currentAcceptSocket; // 
	HANDLE m_completePort; // 
	HANDLE m_ioCompletePort; // 
	LPFN_ACCEPTEX lpfnAcceptEx; // 
	WSAOVERLAPPED m_acceptUnit; // 
	bool tryNewConn(); // 
};

#endif // !WIN_IOCP_SERVER_H