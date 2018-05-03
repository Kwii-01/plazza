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

int Parser::verif_valid_vector(std::vector<std::string> &vector_commands)
{
	for (auto line : vector_commands) {
		int count_words = 0;
		int place_last = 0;

		for (unsigned int i = 0; i < line.size(); i++) 
			if (isspace(line[i])) {
				++count_words;
				place_last = i;
			}
		if (count_words == 0)
			return 84;
		std::string last = line.substr(place_last + 1, line.length());
		int error = 84;
		for (int i = 0; i < 6; i++)
			if (last == infos[i].str)
				error = 0;
		if (error == 84)
			return (error);
	}
	return (0);
}

void Parser::considered_filename(const std::string &substr, std::string macro)
{
	for (auto action : actions) {
		if (action->filename == substr) {
			int i = 0;
			for (; i < 6; i++)
				if (macro == infos[i].str)
					break ;
			action->vect_info.push_back(infos[i].value);
			return ;
		}
	}
	s_cmdinfo *to_add = new(s_cmdinfo);
	int i = 0;
	for (; i < 6; i++)
		if (macro == infos[i].str)
			break ;
	to_add->vect_info.push_back(infos[i].value);
	to_add->filename = substr.substr(0, substr.length());
	actions.push_back(to_add);
}

void Parser::fill_action(std::vector<std::string> &vector_commands)
{
	for (auto line : vector_commands) {
		std::string substr;
		std::istringstream stream(line);
		while (stream.tellg() != -1) {
			stream >> substr;
			if (stream.tellg() != -1)
				considered_filename(substr, line.substr(line.find_last_of(' ') + 1, line.length()));
		}
	}
}

void Parser::epur_str(std::string &str)
{
	bool space = false;
	auto p = str.begin();

	for (auto ch : str)
		if (std::isspace(ch))
			space = p != str.begin();
		else {
			if (space) *p++ = ' ';
			*p++ = ch;
			space = false;
		}
	str.erase(p, str.end());
}

int Parser::fill_vector_commands(std::vector<std::string> &vector_commands, const std::string &cmdline)
{
	int x = 0;
	int last = 0;
	std::string cmd;

	while (cmdline[x] && cmdline[x] != '\0') {
		if (cmdline[x] == ';' || cmdline[x + 1] == '\0') {
			if (cmdline[x] == ';')
				cmd = cmdline.substr(last, x - last);
			else
				cmd = cmdline.substr(last, (x + 1) - last);
			epur_str(cmd);
			last = x + 1;
			if (cmd != "")
				vector_commands.push_back(cmd);
		}
		++x;
	}
	return (verif_valid_vector(vector_commands));
}

std::vector<s_cmdinfo *> &Parser::run(const std::string &cmdline)
{
	std::vector<std::string> vector_commands;

	if (fill_vector_commands(vector_commands, cmdline) != 84)
		fill_action(vector_commands);
	/*for (auto i : actions) {
		std::cout << i->filename << std::endl;
		for (auto k : i->vect_info)
			std::cout << k << " ";
		std::cout << std::endl;
	}
	std::cout << "end parsing" << std::endl;*/
	return (actions);
}
