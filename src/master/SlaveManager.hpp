/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** header
*/

#ifndef SLAVEMANAGER_HPP_
	#define SLAVEMANAGER_HPP_

#include "plazza.hpp"

extern serv_t	serv_g;

class SlaveManager {
	public:
		SlaveManager(t_masterinfo masterinfo) : _masterinfo(masterinfo) {}
		void	Interpret(std::vector<s_cmdinfo *> &, t_masterinfo &);
	private:
		int	checkFreeToWork();
		void	checkWhoIsNotWorking();
		void	CreateSlave(s_cmdinfo info, t_masterinfo);
		void	DeleteSlave();
		void	AssignWorks(t_client &, s_cmdinfo &);
		std::vector<t_client>	_clients;
		t_masterinfo		_masterinfo;
};

#endif /* !SLAVEMANAGER_HPP_ */
