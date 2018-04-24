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
#include <iostream>
#include <string.h>
#include <stdio.h>
Slave::Slave(t_masterinfo &data)
: _socket(-1)
{
//	fd_set	read_fd_set;
	struct sockaddr_in	server;

	_socket = socket(AF_INET, SOCK_STREAM, 0);
	std::cout << "avant le socket" << std::endl;
	if (_socket == -1)
		throw Err::ServerError("Couldn't create the slave: socket.");
	std::cout << "après le socket" << std::endl;
	server.sin_family = AF_INET;
	server.sin_port = htons(data.port);
	server.sin_addr.s_addr = htonl(data.addr);
	std::cout << "avant le connect" << std::endl;
	//if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0)
        //	std::cerr << "error select" << std::endl;
	_fd = -1;
	while (_fd == -1) {
		_fd = connect(_socket, (struct sockaddr *)&server, sizeof(server));
	}
	if (_fd == -1) {
		close(_socket);
		throw Err::ServerError("Couldn't create the slave: connect.");
	}
	std::cout << "après le connect" << std::endl;
	std::string name;
	std::getline(std::cin, name);
	if (name != "")
		dprintf(0, "ça fonctionne = %s\n", name.c_str());
	//char oui[] = "JE SUIS LE CLIENT\n";
/* 	std::cout << "après le connect" << std::endl;
	write(, "caca\n", strlen("caca\n"));
	std::cout << "après le connect" << std::endl; */
}

Slave::~Slave()
{
}