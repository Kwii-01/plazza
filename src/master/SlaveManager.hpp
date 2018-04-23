/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** header
*/

#ifndef SLAVEMANAGER_HPP_
	#define SLAVEMANAGER_HPP_

#include "plazza.hpp"

class SlaveManager {
	public:
		SlaveManager(t_masterinfo masterinfo) : _masterinfo(masterinfo) {}
		void	Interpret(std::vector<s_cmdinfo *> &);
	private:
		int	checkFreeToWork():
		void	CreateSlave();
		void	DeleteSlave();
		std::vector<t_client>	_clients;
		t_masterinfo		_masterinfo;
};

#endif /* !SLAVEMANAGER_HPP_ */
