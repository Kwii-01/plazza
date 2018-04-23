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
#include "Server.hpp"

Server::Server()
: _pe(getprotobyname("TCP")), _port(-1), _socket(-1), _addr(0)
{

}

void	Server::createServer(int port)
{
	_port = port;
	if (port <= 1024 || port >= 65535)
		findPort();
	if (!_pe)
		throw Err::ServerError("Server creation failed: getprotobyname.");
	_socket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, _pe->p_proto);
	if (_socket == -1)
		throw Err::ServerError("Server creation failed: socket.");
	bindServer();
	if (listen(_socket, 42) == -1) {
		closeServer();
		throw Err::ServerError("Server creation failed: listen.");
	}
}

void	Server::closeServer()
{
	if (_socket != -1) {
		if (close(_socket) == -1)
			throw Err::ServerError("Couldn't close the server.");
	}
	_socket = -1;
	_port = -1;
	_addr = 0;
}

void	Server::findPort() noexcept
{
	std::pair<int, int>	p;

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
	struct sockaddr_in	s_in;

	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(_port);
	s_in.sin_addr.s_addr = INADDR_ANY;
	if (bind(_socket, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		closeServer();
		throw Err::ServerError("bind failed.");
	}
}