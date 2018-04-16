/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** master's header
*/

#ifndef MASTER_HPP_
	#define MASTER_HPP_

class	Master
{
	public:
		Master(int threads) : _maxThreads(threads) {}
		~Master();
		int	exec();
	private:
		int	_maxThreads;
};

#endif /* !MASTER_HPP_ */
