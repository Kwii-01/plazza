/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** source
*/

#include "ThreadPool.hpp"
#include <exception>
#include <unistd.h>
#include <time.h>
#include <thread>
#include 

ThreadPool::ThreadPool(int nbrMaxThreads/* , std::function<void()> pipi */)
{

//	std::thread type (, );
//	std::mutex mtx;
	int i = 0;
	time_t start = time(NULL);
	str = "";
	Parse
	std::vector<std::string>	new_vector = 
	for (int i = 0; i < nbrMaxThreads; ++i) {
		mutexes.push_back(new std::mutex);
		threads.push_back(new std::thread(toDo, i, this, start));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
//	_maxThreads = nbrMaxThreads;
/* 	while (std::cin >> str) *//* start + 5 > time(NULL)) *//*  {
		_maxThreads = nbrMaxThreads;
		std::cout << "ANATOLE EST UN PD" << std::endl; */
	//	std::cin >> str;
//		std::this_thread::sleep_for(std::chrono::milliseconds(50));	
/* 		std::cout << _maxThreads << std::endl;
		while (_maxThreads > 0);
		str = "";
	} */
 	for (auto& thread : threads) {
		std::cout << "Thread's destruction : " << i << std::endl;		 
		thread->join(/* thread, NULL */);
		delete(thread);
		i++;
	}
	threads.clear();
/* 	for (int i = 0; i < nbrMaxThreads; ++i) {
		threads.push_back(new std::thread(toDo, i, this));
		usleep(500);
	} */
}

void ThreadPool::toDo(int caca, ThreadPool *me, time_t start)
{
		//std::cout << caca << std::endl;
//	for (int i = 0; i != 2000; ++i)
	std::cout << "Thread's creation : " << caca << std::endl;
	int id = caca;
	//bool read = false;
	while (start + 5 > time(NULL)) {
		me->mutexes[id]->lock();
		if (me->str != ""/*  && read == false */) {
		//	std::cout << "The str is full of : " << me->str << std::endl;
		//	std::cout << "In thread : " << me->_maxThreads << std::endl;		
		//	me->_maxThreads -= 1;
		//	std::cout << "In thread : " << me->_maxThreads << std::endl;
		//	read = true;
		}
		/* if (me->str == "")
			read = false; */
		me->mutexes[id]->unlock();
	//s	std::this_thread::sleep_for(std::chrono::milliseconds(50));			
//		else	
//			std::cout << "The str is empty." << std::endl;
	}
}

ThreadPool::~ThreadPool()
{

}
