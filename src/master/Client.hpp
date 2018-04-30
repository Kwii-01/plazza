/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Client
*/

#ifndef CLIENT_HPP_
	#define CLIENT_HPP_

#include "IntSocket.hpp"
#include "Plazza.hpp"

class Client {
	public:
		Client();
		~Client();
		int	connect(int);
		int	getSocket() { return _socket; }
		int	getServFd() { return _serFd; }
	private:
		int	_socket;
		int	_serFd;
};

#endif /* !CLIENT_HPP_ */
