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
#include "Slave.hpp"
#include "IntSocket.hpp"

Slave::Slave()
{
	working = false;
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
	int		work[1];
 	s_cmdinfo	infos;
	IntSocket	handleSocket;
	ThreadPool	threads(2);

	work[0] = 0;
	handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
	if (handleSocket.intRecv(_client.getSocket(), &infos, sizeof(infos), 0) == -1)
		std::cout << "Wut" << std::endl;
	std::cout <<  "NAME: " << infos.filename << std::endl;
	working = true;
	while (1) {
		if (working) {
			threads.newInstruction(&infos);
			work[0] = 1;
			while (pool->finishWork() == false) {
				handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			}
			working = false;
		} else {
			work[0] = 0;
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intRecv(_client.getSocket(), &infos, sizeof(infos), 0);
			working = true;
		}
	}
}
