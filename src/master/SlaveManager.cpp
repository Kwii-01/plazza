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

void	SlaveManager::CreateSlave(s_cmdinfo *, t_masterinfo masterinfo)
{
	int	pid = fork();
	struct sockaddr_in	s_cl;
	socklen_t		s_size = sizeof(s_cl);

	if (pid > 0) {
		std::cout << "Waiting connexion\n" << std::endl;
		serv_g._client = accept(serv_g._server, (struct sockaddr *)&s_cl, &s_size);
		if (serv_g._client == -1)
			throw Err::ServerError("Couldn't accept the connexion.");
		std::cout << "Client connected\n" << std::endl;
	}
	if (pid == 0) {
		Slave	slave(masterinfo);
		// EXE C FCNT DU SLAVE
		close(slave.getSocket());
		exit(0);
	}
}

void	SlaveManager::DeleteSlave()
{

}