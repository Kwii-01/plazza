/*
** EPITECH PROJECT, 2018
** plazza source
** File description:
** 
*/

#include "SlaveManager.hpp"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include "../slave/Slave.hpp"
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../tool/Error.hpp"
#include <unistd.h>
#include <stdio.h>
int	SlaveManager::checkFreeToWork()
{
	for (std::size_t i = 0; i < _clients.size(); ++i) {
		if (_clients[i].working == false)
			return i;
	}
	return -1;
}

void    SlaveManager::Interpret(std::vector<s_cmdinfo *> &cmd_info,
t_masterinfo &masterinfo)
{
	int	reassign = -1;

	for (auto info : cmd_info) {
		if (!(_clients.empty()))
			reassign = checkFreeToWork();
		if (reassign >= 0)
			AssignWorks(_clients[reassign], info);
		else
			CreateSlave(info, masterinfo);
	}
	if (!(cmd_info.empty()))
		cmd_info.clear();
}

void	SlaveManager::AssignWorks(t_client &client, s_cmdinfo *info)
{
	std::cout << "Assign" << std::endl;
	std::cout << info->filename << std::endl;
	std::cout << client.working << std::endl;
}

#include <string.h>

void    SlaveManager::CreateSlave(s_cmdinfo *, t_masterinfo masterinfo)
{
	t_client	new_client;
	struct sockaddr_in	client;
	socklen_t		size = sizeof(client);


	new_client.pid = fork();
	if (new_client.pid == 0) {
		std::cout << "CHildren" << std::endl;
		//if (new_client.fd == -1)
		//	throw Err::ServerError("Couldn't accept the client.");
		std::cout << "Before creating" << std::endl;
		Slave		new_slave(masterinfo);
		serv_g._pid = new_client.pid;
		std::cout << "Create Done" << std::endl;
		_clients.push_back(new_client);
		dprintf(new_slave.getFd(), "JE SUIS LE SERVEUR\n");

 		char buff[100];
		int e = 0;
		while ((e = read(new_slave.getFd(), buff, 100) < 0));
		buff[e] = '\0';
		if (e != 0)
			printf("kek\n");
		exit(0);
	}
	if (new_client.pid > 0) {
		std::cout << "Father" << std::endl;
			new_client.fd = -1;
		//while (new_client.fd == -1) {
		//	std::cout << "lol" << std::endl;
		new_client.fd = accept(serv_g._server, (struct sockaddr *)&client, &size);
		//}
		std::cout << "Father" << std::endl;
	}
}

void    SlaveManager::DeleteSlave()
{

}