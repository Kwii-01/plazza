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
#include "../slave/Parse_file.hpp"

class ThreadPool {
	public:
		ThreadPool(int);
		~ThreadPool();
	private:
		static void	toDo(int, ThreadPool *);
		std::vector<std::thread *>	threads;
		std::vector<std::mutex *>	mutexes;
		std::vector<t_threads_info>	vec_threads_info;
		std::string			str;
		int				_maxThreads;
		Parsefiles			parse;
		bool				_end = false;
};

#endif /* !THREADPOOL_HPP_ */
