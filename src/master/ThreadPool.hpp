/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** header
*/

#ifndef THREADPOOL_HPP_
	#define THREADPOOL_HPP_

#include <iostream>       // std::cout
#include <thread>
#include <vector>
#include <../../include/plazza.hpp>

class ThreadPool {
	public:
		ThreadPool(int nbrMaxThreads);
		~ThreadPool();
	private:
                std::vector<std::thread>   threads;
};

#endif /* !THREADPOOL_HPP_ */
