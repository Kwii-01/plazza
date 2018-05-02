/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Server
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "plazza.hpp"
#include <iostream>
#include "IntSocket.hpp"
#include "Server.hpp"

Server::Server()
	: _pe(getprotobyname("TCP")), _port(-1), _socket(-1), _addr(0)
{

}

void	Server::createServer(int port)
{
	IntSocket	iSock;

	_port = port;
	if (port <= 1024 || port >= 65535)
		findPort();
	if (!_pe)
		throw Err::ServerError("Server creation failed: getprotobyname.");
	_socket = iSock.intSocket(AF_INET, SOCK_STREAM, _pe->p_proto);
	if (_socket == -1)
		throw Err::ServerError("Server creation failed: socket.");
	bindServer();
	if (iSock.intListen(_socket, 42) == -1) {
		closeServer();
		throw Err::ServerError("Server creation failed: listen.");
	}
}

void	Server::closeServer()
{
	IntSocket	iSock;

	if (_socket != -1) {
		if (iSock.intClose(_socket) == -1)
			throw Err::ServerError("Couldn't close the server.");
	}
	_socket = -1;
	_port = -1;
	_addr = 0;
}

void	Server::findPort() noexcept
{
	std::pair<int, int>	p;

	_port = -1;
	while (_port == -1) {
		p.first = rand() % 255 + 1;
		p.second = rand() % 255 + 1;
		_port = p.first * 256 + p.second;
		if (_port < 1024 || _port > 65535)
			_port = -1;
	}
}

void	Server::bindServer()
{
	IntSocket	iSock;
	struct sockaddr_in	s_in;

	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(_port);
	s_in.sin_addr.s_addr = INADDR_ANY;
	if (iSock.intBind(_socket, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		closeServer();
		throw Err::ServerError("bind failed.");
	}
	_addr = inet_addr("127.0.0.1");
}

int	Server::acceptClient(int fd)
{
	struct sockaddr_in	s_cl;
	socklen_t		s_size = sizeof(s_cl);
	int			clientFd;
	IntSocket		iSock;

	clientFd = iSock.intAccept(fd, (struct sockaddr *)&s_cl, &s_size);
	if (clientFd == -1)
		throw Err::ServerError("Couldn't accept the connexion.");
	return clientFd;
}
