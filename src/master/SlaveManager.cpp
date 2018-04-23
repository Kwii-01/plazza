/*
** EPITECH PROJECT, 2018
** plazza source
** File description:
** 
*/

#include "SlaveManager.hpp"

//void    SlaveManager

int	SlaveManager::checkFreeToWork()
{
	for (unisgned int i = 0; i < _clients.size(); ++i) {
		if (_clients[i].working == false)
			return i;
	}
	return -1;
}

void    SlaveManager::Interpret(std::vector<s_cmdinfo *> &cmd_info)
{
	int	reassign = -1;

	for (auto it : info) {
		if (!(_clients.empty()))
			reassign = checkFreeToWork();
		if (reassign < 0) {
			AssignWorks(_clients[reassign], info);
		}
	}
	if (!(cmd_info.empty()))
		cmd_info.clear();
}

void	SlaveManager::AssignWorks(t_client &client, s_cmdinfo *info)
{
	std::cout << info.info << std::endl;
}

void    SlaveManager::CreateSlave()
{
	
}

void    SlaveManager::DeleteSlave()
{

}