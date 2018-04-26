/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** slave
*/

#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <utility>
#include <iostream>
#include <string.h>
#include "../tool/Error.hpp"
#include "Slave.hpp"
#include "../master/IntSocket.hpp"

Slave::Slave()
: _socket(-1), _servFd(-1)
{

}

int	Slave::connectServer(t_masterinfo &data)
{
	IntSocket		iSock;
	struct sockaddr_in	server;
	struct protoent	*pe = getprotobyname("TCP");

	_socket = iSock.intSocket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (_socket == -1)
		throw Err::ServerError("socket problem at creation of the client.");
	server.sin_family = AF_INET;
	server.sin_port = htons(data.port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	std::cout << "Connecting to the server\n" << std::endl;
	_servFd = iSock.intConnect(_socket, (struct sockaddr *)&server, sizeof(server));
	if (_servFd == -1)
		throw Err::ServerError("Connec error.");
	std::cout << "Connected to the server\n" << std::endl;
	return (_socket);
}

Slave::~Slave()
{
}
