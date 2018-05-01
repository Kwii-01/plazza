/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** slave
*/

#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <utility>
#include <iostream>
#include <string.h>
#include "Slave.hpp"
#include "IntSocket.hpp"
#include <future>

Slave::Slave()
{
 	_timer = new Timer();
	_mutex = new std::mutex;
	_statu = "starting";
//	_mutex->unlock();
	auto myLambda = [=]{timerFunc(this);};
	_threadTimer = new std::thread(myLambda);
	_working = false;
}

void	Slave::timerFunc(Slave *)
{
	//promObj->set_value(35);

// 	std::cout << "statu = " << _statu << std::endl;
//	while (_timer->checkTimer() == false);
//	std::cout << "oui" << std::endl;
/*	 {
		_mutex->lock();
		std::cout << _statu << std::endl;
		if (_statu == "check true") {
			std::cout << "non" << std::endl;
			_timer->setCheck(true);
		}
		_mutex->unlock();
	} */
/* 	std::cout << "close" << std::endl;
	if (close(_client.getSocket()) == -1)
		std::cerr << "problème close" << std::endl;
	else
		std::cout << "end close " << std::endl;
	exit(0);
 */}

int	Slave::connectServer(t_masterinfo &data)
{
	_maxThreads = data.maxThreads;
	return _client.connect(data.port);
}

Slave::~Slave()
{
}

void	Slave::run()
{
	int		work[1];
 	s_cmdinfo	infos;
	IntSocket	handleSocket;
	ThreadPool	threads(_maxThreads);

	work[0] = 0;
	handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
	handleSocket.intRecv(_client.getSocket(), &infos, sizeof(infos), 0);
	_working = true;
	while (1) {
		if (_working) {
	//		_timer->setCheck(false);
			threads.newInstruction(&infos);
			work[0] = 1;
			while (threads.finishWork() == false)
				handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
//			_timer->setCheck(true);
			//s_statu = "check true";
			threads.emptyVec();
			_working = false;
		} else {
			work[0] = 0;
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intRecv(_client.getSocket(), &infos, sizeof(infos), 0);
			_working = true;
		}
	}
}