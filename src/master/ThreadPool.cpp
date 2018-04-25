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

ThreadPool::ThreadPool(int nbrMaxThreads/* , std::function<void()> pipi */)
{
	int i = 0;
	str = "";
	std::vector<std::string>	new_vector = parse.open_file("caca.txt");

	vec_threads_info.push_back({0, new_vector, 0,
	static_cast<int>(new_vector.size() / 2), false});
	vec_threads_info.push_back({1, new_vector,
	static_cast<int>((new_vector.size() / 2) + 1),
	static_cast<int>(new_vector.size()), false});
	for (int i = 0; i < nbrMaxThreads; ++i) {
		mutexes.push_back(new std::mutex);
		threads.push_back(new std::thread(toDo, i, this));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	_end = true;
 	for (auto &thread : threads) {
		thread->join();
		delete(thread);
		i++;
	}
	vec_threads_info.clear();
	threads.clear();
}

void ThreadPool::toDo(int caca, ThreadPool *me)
{
	int id = caca;

	while (me->_end == false) {
		me->mutexes[id]->lock();
		for (auto thread_info : me->vec_threads_info) {
			if (id == thread_info.id && thread_info.finish == false) {
				me->parse.parse_regex(Information::PHONE_NUMBER,
				thread_info.file, thread_info.start, thread_info.end);
				thread_info.finish = true;
				return;				
			}
		}
		me->mutexes[id]->unlock();
	}
}

ThreadPool::~ThreadPool()
{

}
