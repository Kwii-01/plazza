/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** slave's header
*/

#ifndef SLAVE_HPP_
	#define SLAVE_HPP_

#include "../../include/plazza.hpp"

class Slave
{
	public:
		Slave(t_masterinfo &);
		~Slave();
		int	getFd() { return _socket; };
	private:
		int	_socket;
		int	_fd;
};

#endif /* !SLAVE_HPP_ */
