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
		SlaveManager(t_masterinfo masterinfo, int gui) : _masterinfo(masterinfo), _gui(gui) {}
		void	Interpret(std::vector<s_cmdinfo *> &, t_masterinfo &);
		void	WaitFinishWork();
	private:
		void	create_window();
		int	checkFreeToWork();
		void	checkWhoIsNotWorking();
		void	CreateSlave(s_cmdinfo info, t_masterinfo);
		void	DeleteSlave();
		void	AssignWorks(t_client &, s_cmdinfo &);
		std::vector<t_client>	_clients;
		t_masterinfo		_masterinfo;
		int _gui;
};

#endif /* !SLAVEMANAGER_HPP_ */
