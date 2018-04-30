/*
** EPITECH PROJECT, 2018
** Cli
** File description:
** header
*/

#ifndef CLI_HPP_
	#define CLI_HPP_

#include "plazza.hpp"

extern serv_t	serv_g;

class Cli
{
	public:
		Cli() {}
		~Cli() {}
		void	mainLoop(t_masterinfo &);
		std::vector<s_cmdinfo *>	getCmd();
};

#endif /* !CLI_HPP_ */
