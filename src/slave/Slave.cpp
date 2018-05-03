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
}

int	Slave::connectServer(t_masterinfo &data)
{
	_maxThreads = data.maxThreads;
	return _client.connect(data.port);
}

Slave::~Slave()
{
}

void timer(char *is_finished, int socket)
{
	time_t this_time;
	time_t last_time;
	time(&this_time);
	last_time = this_time;
	while (true) {
		time(&this_time);
		if (is_finished[0] == 'y') {
			last_time = this_time;
			is_finished[0] = 'n';
		}
		if (difftime(this_time, last_time) > 5.0f) {
			is_finished[0] = 'y';
			close(socket);
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
	std::thread thread(timer, str, _client.getSocket());
	while (1) {
		if (_working) {
			str[0] = 'y';
			for (;infos.vect_info.size() > 0;) {
				threads.newInstruction(&infos, 0);
				work[0] = 1;
				while (threads.finishWork() == false)
					handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
				threads.emptyVec();
				_working = false;
				infos.vect_info.erase(infos.vect_info.begin());
			}
		} else {
			if (str[0] == 'y') {
				close(_client.getSocket());
				exit(0); 
			}
			work[0] = 0;
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intSend(_client.getSocket(), work, sizeof(int), 0);
			handleSocket.intRecv(_client.getSocket(), &infos, sizeof(infos), 0);
			_working = true;
		}
		if (str[0] == 'y') {
			close(_client.getSocket());
			exit(0);
		}
	}
}
