/*
** EPITECH PROJECT, 2018
** plazza source
** File description:
** 
*/

#include <iostream>
#include "Server.hpp"
#include "SlaveManager.hpp"
#include "Slave.hpp"
#include "Error.hpp"
#include "IntSocket.hpp"

int	SlaveManager::checkFreeToWork()
{
	for (std::size_t i = 0; i < _clients.size(); ++i) {
		if (_clients[i].working == false)
			return i;
	}
	return -1;
}

void    SlaveManager::Interpret(std::vector<s_cmdinfo *> &cmd_info, t_masterinfo &masterinfo)
{
	int	reassign = -1;

	for (auto info : cmd_info) {
		if (!(_clients.empty()))
			reassign = checkFreeToWork();
		if (reassign >= 0)
			AssignWorks(_clients[reassign], *info);
		else
			CreateSlave(*info, masterinfo);
	}
	if (!(cmd_info.empty()))
		cmd_info.clear();
}

void	SlaveManager::AssignWorks(t_client &client, s_cmdinfo &info)
{
	IntSocket	iSock;
	int		i[1];

	if (iSock.intRecv(client.fd, i, sizeof(i), 0) == -1)
		throw Err::Error("Recv failed!!");
	if (i[0] == 0 && !client.working) {
		std::cout << info.filename << std::endl;
		if (iSock.intSend(client.fd, &info, sizeof(info), 0) == -1)
			throw Err::Error("Send failed");
		client.working = true;
	}
}

void	SlaveManager::checkWhoIsNotWorking()
{
	IntSocket	iSock;
	int		i[1];

	for (auto slave : _clients) {
		iSock.intRecv(slave.fd, i, sizeof(int), 0);
		if (i[0] == 0)
			slave.working = false;
	}
}

void	SlaveManager::CreateSlave(s_cmdinfo info, t_masterinfo masterinfo)
{
	Slave		slave;
	Server		serv;
	IntSocket	iSock;
	t_client	client;
	serv_g._pid = fork();

	if (serv_g._pid > 0) {
		serv_g._client = serv.acceptClient(serv_g._server);
		client.pid = serv_g._pid;
		client.fd = serv_g._client;
		client.working = false;
		/*int lol[1];
		iSock.intRecv(client.fd, lol, sizeof(lol), 0);
		if (lol[0] == 0)
			std::cout << "JE VAIS TRAVAILLER" << std::endl;
		iSock.intSend(client.fd, &info, sizeof(info), 0);*/
		AssignWorks(client, info);
		_clients.push_back(client);
	}
	if (serv_g._pid == 0) {
		serv_g._client = slave.connectServer(masterinfo);
		slave.run();
		close(slave.getSocket());
		exit(0);
	}
}

void	SlaveManager::DeleteSlave()
{

}