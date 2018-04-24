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
		int	getServFd() { return _servFd; };
		int	getSocket() { return _socket; };
		void	setServFd(int fd) { _servFd = fd; };
		void	setSocket(int socket) { _socket = socket; };
	private:
		int	_socket;
		int	_servFd;
};

#endif /* !SLAVE_HPP_ */
