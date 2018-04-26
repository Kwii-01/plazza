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
		void		newInstruction(s_cmdinfo *);
	private:
		void		divide_by_threads(std::vector<std::string> &, int);
		void	toDo(ThreadPool *, int);
		std::vector<std::thread *>	threads;
		std::mutex	 		*mutex;
		std::vector<t_threads_info>	_vecThreadsInfos;
		Parsefiles			_parse;
		bool				_end;
		int				_nbrMaxThreads;
		std::string			_state;
		std::vector<std::string>	_action;
};

#endif /* !THREADPOOL_HPP_ */
