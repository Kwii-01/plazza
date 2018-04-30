/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** client
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
#include "Error.hpp"
#include "Client.hpp"

Client::Client()
{
}

Client::~Client()
{
}

int	Client::connect(int port)
{
	IntSocket		iSock;
	struct sockaddr_in	server;
	struct protoent	*pe = getprotobyname("TCP");

	_socket = iSock.intSocket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (_socket == -1)
		throw Err::ServerError("socket problem at creation of the client.");
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	_serFd = iSock.intConnect(_socket, (struct sockaddr *)&server, sizeof(server));
	if (_serFd == -1)
		throw Err::ServerError("Connec error.");
	return (_socket);
}