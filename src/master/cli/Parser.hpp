//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include <vector>
#include <iostream>
#include "plazza.hpp"

class Parser
{
public:
	Parser();
	std::vector<s_cmdinfo *> &run(const std::string &cmdline);
private:
	void considered_filename(const std::string &substr, std::string macro);
	void fill_action(std::vector<std::string> &vector_commands);
	void epur_str(std::string &str);
	int verif_valid_vector(std::vector<std::string> &vector_commands);
	int fill_vector_commands(std::vector<std::string> &vector_commands, const std::string &cmdline);
	std::vector<s_cmdinfo *> actions;
};

#endif /*!PARSER_HPP_*/
