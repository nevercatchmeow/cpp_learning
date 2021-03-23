#include "Server.h"
#include <string>
#include <cassert>

Server::Server(u_short p)
	: m_port(p),
	m_listenSocket(INVALID_SOCKET),
	m_completePort(NULL),
	lpfnAcceptEx(nullptr),
	m_currentAcceptSocket(INVALID_SOCKET),
	m_ioCompletePort(NULL),
	m_running(false),
	m_acceptBuffer(1024){}

Server::~Server()
{

}

