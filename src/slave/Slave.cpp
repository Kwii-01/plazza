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
#include <thread>

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

void timer(char *is_finished)
{
	time_t this_time;
	time_t last_time;
	time(&this_time);
	last_time = this_time;
	while (true) {
		time(&this_time);
		if (difftime(this_time, last_time) > 5.0f) {
			is_finished[0] = 'y';
			std::cout << "5 sc\n";
			return ;
		}
	}
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
	char str[2];
	str[0] = 'n';
	str[1] = '\0';
	std::thread thread(timer, str);
	while (1) {
		if (_working) {
			//		_timer->setCheck(false);
			for (;infos.vect_info.size() > 0;) {
				threads.newInstruction(&infos, 0);
				work[0] = 1;
				while (threads.finishWork() == false)
					handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
//				_timer->setCheck(true);
				//s_statu = "check true";
				threads.emptyVec();
				_working = false;
				infos.vect_info.erase(infos.vect_info.begin());
			}
		} else {
			std::cout << "else " << str << std::endl;
			if (str[0] == 'y') {
				if (close(_client.getSocket()) == -1)
					std::cerr << "problème close" << std::endl;
				else
					std::cout << "end close " << std::endl;
				exit(0); 
			}
			work[0] = 0;
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intRecv(_client.getSocket(), &infos, sizeof(infos), 0);
			_working = true;
		}
		std::cout << "lopp" << str << std::endl;
	}
}
