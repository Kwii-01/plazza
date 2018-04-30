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
#include "ThreadPool.hpp"

class Slave
{
	public:
		Slave();
		~Slave();
		int	connectServer(t_masterinfo &);
		int	getServFd() { return _client.getSerFd(); };
		int	getSocket() { return _client.getSocket(); };
		void	run();
	private:
		Client		_client;
		bool		working;
		ThreadPool	*pool;
};

#endif /* !SLAVE_HPP_ */
