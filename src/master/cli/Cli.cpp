/*
** EPITECH PROJECT, 2018
** Cli
** File description:
** source
*/

#include <iostream>
#include "Parser.hpp"
#include "SlaveManager.hpp"
#include "Cli.hpp"

void	Cli::mainLoop(t_masterinfo &data)
{
	SlaveManager			slv(data);
	std::vector<s_cmdinfo *>	cmds;

	while (serv_g._status != -1) {
		cmds = getCmd();
		slv.Interpret(cmds);
	}
}

std::vector<s_cmdinfo *>	Cli::getCmd()
{
	Parser				pars;
	std::string			s;

	getline(std::cin, s);
	return pars.run(s);
}