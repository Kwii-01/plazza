/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** slave's header
*/

#ifndef SLAVE_HPP_
	#define SLAVE_HPP_

#include "Client.hpp"
#include "plazza.hpp"

class Slave
{
	public:
		Slave();
		~Slave();
		int	connectServer(t_masterinfo &);
		int	getServFd() { return _servFd; };
		int	getSocket() { return _socket; };
		void	setServFd(int fd) { _servFd = fd; };
		void	setSocket(int socket) { _socket = socket; };
		void	run();
	private:
		int	_socket;
		int	_servFd;
		Client	_client;
};

#endif /* !SLAVE_HPP_ */
