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
#include "Error.hpp"
#include "Slave.hpp"
#include "IntSocket.hpp"

Slave::Slave()
: _socket(-1), _servFd(-1)
{

}

int	Slave::connectServer(t_masterinfo &data)
{
	return _client.connect(data.port);
}

Slave::~Slave()
{
}

void	Slave::run()
{
	while (1);
}
