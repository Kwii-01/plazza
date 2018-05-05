/*
** EPITECH PROJECT, 2018
** Cli
** File description:
** header
*/

#ifndef CLI_HPP_
	#define CLI_HPP_

#include "SlaveManager.hpp"
#include "plazza.hpp"

extern serv_t	serv_g;

class Cli
{
	public:
		Cli() {}
		~Cli() {}
		void	mainLoop(t_masterinfo &);
	private:
		void	updateCmd(std::vector<s_cmdinfo *> &, t_masterinfo &);
		std::vector<s_cmdinfo *>	getCmd(SlaveManager &);
};

#endif /* !CLI_HPP_ */
