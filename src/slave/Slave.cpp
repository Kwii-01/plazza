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
#include "../tool/Error.hpp"
#include "Slave.hpp"

Slave::Slave(t_masterinfo &data)
: _socket(-1)
{
	struct sockaddr_in	server;

	_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (_socket == -1)
		throw Err::ServerError("Couldn't create the slave.");
	server.sin_family = AF_INET;
	server.sin_port = htons(data.port);
	server.sin_addr.s_addr = htonl(data.addr);
	if (connect(_socket, (struct sockaddr *)&server, sizeof(server)) == -1) {
		close(_socket);
		throw Err::ServerError("Couldn't create the slave.");
	}
}

Slave::~Slave()
{
}
