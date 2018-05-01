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
#include "Timer.hpp"
#include <future>

class Slave
{
	public:
		Slave();
		~Slave();
		int	connectServer(t_masterinfo &);
		int	getServFd() { return _client.getSerFd(); };
		int	getSocket() { return _client.getSocket(); };
		void	run();
		void	timerFunc(Slave *slave);	
	private:
		Client		_client;
		bool		_working;
		int		_maxThreads;
		std::thread	*_threadTimer;
		Timer		*_timer;
		std::string	_statu;
		std::mutex	*_mutex;
};

#endif /* !SLAVE_HPP_ */
