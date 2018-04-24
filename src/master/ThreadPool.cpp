/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** source
*/

#include "ThreadPool.hpp"

void to_do(int caca)
{

}

ThreadPool::ThreadPool(int nbrMaxThreads, std::function<void()> pipi)
{
//	std::thread type (, );
	for (int i = 0; i < nbrMaxThreads; ++i) {
		threads.push_back(std::thread(pipi));
	}
}


{

}

ThreadPool::~ThreadPool()
{
	
}
