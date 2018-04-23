/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** slave's header
*/

#ifndef SLAVE_HPP_
	#define SLAVE_HPP_

#include "../../plazza.hpp"

class Slave
{
	public:
		Slave(t_masterinfo &)
		~Slave();
	private:
		int	_socket;
};

#endif /* !SLAVE_HPP_ */
