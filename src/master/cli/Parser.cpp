//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Parser.hpp"
#include <sstream>
#include <exception>

Parser::Parser()
{
}

static const t_informations infos[] = {
	{"PHONE_NUMBER", PHONE_NUMBER},
	{"EMAIL_ADDRESS", EMAIL_ADDRESS},
	{"IP_ADDRESS", IP_ADDRESS},
	{"PHONE_NUMBER;", PHONE_NUMBER},
        {"EMAIL_ADDRESS;", EMAIL_ADDRESS},
        {"IP_ADDRESS;", IP_ADDRESS}
};

void Parser::considered_enum(const std::string &substr, const std::string &lastsub)
{
	if (lastsub[lastsub.length() - 1] == ';')
		throw (std::invalid_argument("no filename before enum\n"));
	s_cmdinfo *elem = actions.back();
	int found_info = 84;
	for (int i = 0; i < 6; i++) {
		if (substr == infos[i].str) {
			elem->info = infos[i].value;
			found_info = 0;
			break ;
		}
	}
	if (found_info == 84)
		throw (std::invalid_argument("no such enum\n"));
}

void Parser::considered_filename(const std::string &substr)
{
	s_cmdinfo *elem = actions.back();

	elem->vector_files.push_back(substr);
}

std::vector<s_cmdinfo *> &Parser::run(const std::string &cmdline)
{
	std::istringstream stream(cmdline);
	std::string substr;
	std::vector<std::string> vector_substr;

	while (stream.tellg() != -1) {
		stream >> substr;
		vector_substr.push_back(substr);
	}
	actions.push_back(new s_cmdinfo);
	for (auto iter = vector_substr.begin(); iter != vector_substr.end(); iter++) {
		std::string str = *iter;
		if (str[str.length() - 1] == ';' || iter == vector_substr.end() - 1) {
			if (iter == vector_substr.begin())
				throw (std::invalid_argument("no filename before first enum\n"));
			considered_enum(str, *(iter - 1));
			actions.push_back(new s_cmdinfo);
		}								 
		else
			considered_filename(str);
	}
	return actions;
}
