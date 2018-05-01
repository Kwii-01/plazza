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
	_state = "go";
	mutex = new std::mutex;
	mutex->unlock();
	for (int i = 0; i < nbrMaxThreads; ++i)
		_action.push_back("do nothing");
	for (int i = 0; i < nbrMaxThreads; ++i) {
		auto myLambda = [=]{toDo(this, i);};
		threads.push_back(new std::thread(myLambda));
	}
}

void ThreadPool::toDo(ThreadPool *, int i)
{
	int id = i;

	while (_state == "go") {
		while (mutex->try_lock() == 0);
		if (_action[id] == "do nothing") {
			mutex->unlock();
			continue;
		}
 		for (auto thread_info : _vecThreadsInfos) {
			if (id == thread_info.id && _action[i] == "work") {
				_parse.parse_regex(thread_info.value,
				thread_info.file, thread_info.start, thread_info.end);
				_action[i] = "do nothing";
			}
		}
		mutex->unlock();
	}
}

void ThreadPool::divide_by_threads(std::vector<std::string> &new_vector, s_cmdinfo *infos, int i)
{
	int nbrmaxthreads = _nbrMaxThreads;
	unsigned long int lines = new_vector.size();
	unsigned long int counter = 0;
	int x = 0;

	if (static_cast<int>(lines) < nbrmaxthreads)
		nbrmaxthreads = static_cast<int>(lines);
	while (counter < lines) {
		_vecThreadsInfos.push_back({x, new_vector, static_cast<int>(counter),
					static_cast<int>(lines) / nbrmaxthreads
					+ static_cast<int>(counter), infos->vect_info[i]});
		counter += lines / static_cast<unsigned long int>(nbrmaxthreads);
		counter += static_cast<unsigned long int>(1);
		x++;
	}
}

void	ThreadPool::newInstruction(s_cmdinfo *infos, int i)
{
	std::vector<std::string>	newVector = _parse.open_file(infos->filename);

	divide_by_threads(newVector, infos, i);
	for (std::size_t i = 0; i < _vecThreadsInfos.size(); ++i)
		_action[i] = "work";
}

bool	ThreadPool::finishWork()
{
	bool	exist = true;

	for (int i = 0; i < _nbrMaxThreads; ++i) {
		if (_action[i] == "work")
			exist = false;
	}
	return exist;
}

ThreadPool::~ThreadPool()
{
	std::cout << "oyui" << std::endl;
	_state = "finish";
 	for (auto &thread : threads)// {
		thread->join();
	//	delete(thread);
//	}
	threads.clear();
}