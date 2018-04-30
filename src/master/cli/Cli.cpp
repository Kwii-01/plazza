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
		updateCmd(cmds, data);
		for (auto i : cmds) {
			int h = 0;
			std::cout << "file: " << i->filename << std::endl;
			for (auto e : i->vect_info) {
				std::cout << "h: " << e << std::endl;
				h++;
			}
			std::cout << std::endl;
		}
		//slv.Interpret(cmds, data);
	}
}

void	Cli::updateCmd(std::vector<s_cmdinfo *> &cmd, t_masterinfo &data)
{
	std::size_t	maxCmd = 2 * data.maxThreads;

	for (auto elem : cmd) {
		if (elem->vect_info.size() > maxCmd) {
			std::vector<Information>	newCmd;
			for (std::size_t i = maxCmd; i < elem->vect_info.size(); i++)
				newCmd.push_back(elem->vect_info[i]);
			elem->vect_info.erase(elem->vect_info.begin() + maxCmd, elem->vect_info.end());
			s_cmdinfo newcmd;
			newcmd.filename = elem->filename;
			newcmd.vect_info = newCmd;
			cmd.push_back(&newcmd);
		}
	}
}

std::vector<s_cmdinfo *>	Cli::getCmd()
{
	Parser		pars;
	std::string	s;

	getline(std::cin, s);
	return pars.run(s);
}