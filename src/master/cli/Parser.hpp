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
	std::vector<s_cmdinfo *> &run(const std::string);
private:
	void considered_enum(const std::string &, const std::string &);
	void considered_filename(const std::string &);
	std::vector<s_cmdinfo *> actions;
};

#endif /*!PARSER_HPP_*/
