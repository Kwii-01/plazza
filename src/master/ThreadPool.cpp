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

ThreadPool::ThreadPool(int nbrMaxThreads) : _nbrMaxThreads(nbrMaxThreads)
{
	int	i = 0;
	_end = false;
	std::vector<std::string>	newVector;

	newVector.push_back("");
	while (i < nbrMaxThreads) {
		_vecThreadsInfos.push_back(new t_threads_info{i, newVector, 0, 0, true});
		i++;
	}
	for (int i = 0; i < nbrMaxThreads; ++i) {
		mutexes.push_back(new std::mutex);
		threads.push_back(new std::thread(toDo, i, this));
	}
}

void ThreadPool::toDo(int caca, ThreadPool *me)
{
	int id = caca;

	while (me->_end == false) {
		me->mutexes[id]->lock();
		for (auto thread_info : me->_vecThreadsInfos) {
			if (id == thread_info.id && thread_info.finish == false) {
				std::cout << "false : " << id  << std::endl;				
				me->_parse.parse_regex(Information::PHONE_NUMBER,
				thread_info.file, thread_info.start, thread_info.end);
				thread_info.finish = true;
				return;
			}
		}
		me->mutexes[id]->unlock();
	}
}

void ThreadPool::divide_by_threads(std::vector<std::string> &new_vector, int nbrmaxthreads)
{
	unsigned long int lines = new_vector.size();
	unsigned long int counter = 0;
	int save_nb = nbrmaxthreads;
	int x = 0;

	if (static_cast<int>(lines) < nbrmaxthreads)
		nbrmaxthreads = static_cast<int>(lines);
	while (counter < lines) {
		_vecThreadsInfos.push_back({x, new_vector, static_cast<int>(counter),
					static_cast<int>(lines) / nbrmaxthreads
					+ static_cast<int>(counter), false});
		counter += lines / static_cast<unsigned long int>(nbrmaxthreads);
		counter += static_cast<unsigned long int>(1);
		x++;
	}
	while (nbrmaxthreads < save_nb) {
		_vecThreadsInfos.push_back({x, new_vector, 0, 0, true});
		x++;
		nbrmaxthreads++;
	}
}

void	ThreadPool::newInstruction(s_cmdinfo *)
{
	std::vector<std::string>	newVector = _parse.open_file("caca.txt");
	bool				quit = false;
	bool				tempQuit;	

	std::cout << "non" << std::endl;
	divide_by_threads(newVector, _nbrMaxThreads);	
	while (quit == false) {
		tempQuit = true;
		for (auto threadInfos : _vecThreadsInfos) {
			if (threadInfos.finish == true)
				/* tempQuit = false; */
				break;
		}
		quit = tempQuit;
	}
	for (auto threadInfos : _vecThreadsInfos) {
		threadInfos.finish = false;
			/* tempQuit = false; */
//			break;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	_vecThreadsInfos.erase(_vecThreadsInfos.begin()+_nbrMaxThreads, _vecThreadsInfos.end());
}

ThreadPool::~ThreadPool()
{
	_end = true;
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
 	for (auto &thread : threads) {
		thread->join();
		delete(thread);
	}
	threads.clear();
}
