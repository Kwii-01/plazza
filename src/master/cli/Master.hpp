/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** master's header
*/

#ifndef MASTER_HPP_
	#define MASTER_HPP_

#include "plazza.hpp"

extern serv_t	serv_g;

class	Master
{
	public:
		Master(int nbthread) : _data({0, -1, -1, nbthread}) {}
		~Master();
		int	exec();
	private:
		t_masterinfo	_data;

		void	initServG();
};

#endif /* !MASTER_HPP_ */
