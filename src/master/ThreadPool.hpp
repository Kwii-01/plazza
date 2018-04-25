/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** header
*/

#ifndef THREADPOOL_HPP_
	#define THREADPOOL_HPP_

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <deque>
#include <../../include/plazza.hpp>

class ThreadPool {
	public:
		ThreadPool(int);
		~ThreadPool();
	private:
		static void	toDo(int, ThreadPool *, time_t);
		std::vector<std::thread *>	threads;
		std::vector<std::mutex *>	mutexes;
		std::string			str;
		int				_maxThreads;
};

#endif /* !THREADPOOL_HPP_ */
