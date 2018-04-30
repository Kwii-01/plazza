/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Server
*/

#ifndef SERVER_HPP_
	#define SERVER_HPP_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <utility>
#include "Error.hpp"

class Server
{
	public:
		Server();
		~Server() {}
		void	createServer(int port = 0);
		int	acceptClient(int);
		void	closeServer();
		int	getPort() const noexcept { return _port; }
		int	getSocket() const noexcept { return _socket; }
		int	getAddr() const noexcept { return _addr; }
	private:
		struct protoent	*_pe;
		int		_port;
		int		_socket;
		in_addr_t	_addr;

		void	findPort() noexcept;
		void	bindServer();
};

#endif /* !SERVER_HPP_ */
