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
#include "../slave/slave.hpp"

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
		if (reassign < 0) {
			AssignWorks(_clients[reassign], info);
		}
		else
			CreateSlave(info, masterinfo);
	}
	if (!(cmd_info.empty()))
		cmd_info.clear();
}

void	SlaveManager::AssignWorks(t_client &client, s_cmdinfo *info)
{
	std::cout << info->filename << std::endl;
	std::cout << client.working << std::endl;
	client.
}

void    SlaveManager::CreateSlave(s_cmdinfo *info, t_masterinfo masterinfo)
{
	t_client	new_client;
	Slave		new_slave = new Slave(masterinfo);

	std::cout << info->filename << std::endl;	
	new_client.pid = fork();
	serv_data.pid = new_client.pid;
//	_clients.push_back({});
}

void    SlaveManager::DeleteSlave()
{

}