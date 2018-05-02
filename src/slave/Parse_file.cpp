//
// EPITECH PROJECT, 2018
// parse
// File description:
// file
//

#include <cctype>
#include <fstream>
#include "plazza.hpp"
#include "Parse_file.hpp"

Parsefiles::~Parsefiles()
{
}

Parsefiles::Parsefiles()
{
}

void Parsefiles::check_if_match(std::string str, int x, int count)
{
	int save_x = x;

	if (x > 0 && str[x - 1] != ' ')
		return ;
	for (; str[x]; x++) {
		if (str[x] == ' ' && str[x - 1] == ' ')
			return ;
		else if	(!isdigit(str[x]) && str[x] != ' ')
			return ;
		else if	(isdigit(str[x]))
			count++;
		if (count == 10)
			break ;
	}
	if (count == 10) {
		if (str[x + 1] && str[x + 1] != ' ')
			return ;
		for (int new_count = 0; new_count != 10; save_x++) {
			std::cout << str[save_x];
			if (isdigit(str[save_x]))
				new_count++;
		}
		std::cout << std::endl;
	}
}

void Parsefiles::parse_phone(std::string &line)
{
	for (int x = 0; line[x] != '\0'; x++) {
		if (line[x] == '0' && line[x + 1]) {
			check_if_match(line, x, 0);
		}
	}
}

void Parsefiles::parse_regex(Information information, std::vector<std::string> &file, int from, int to)
{
	std::string substr;
	int current = 0;
	for (auto line : file) {
		current++;
		if (current - 1 < from || current - 1 > to)
			continue ;
		if (information == PHONE_NUMBER)
			parse_phone(line);
		else {
			std::istringstream stream(line);
			if (information == EMAIL_ADDRESS)
				substr = "[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+";
			else if (information == IP_ADDRESS)
				substr = "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}";
			std::regex regex(substr.c_str());
			while (stream.tellg() != -1) {
				stream >>substr;
				if (std::regex_match(substr, regex) == 1)
					std::cout << substr << std::endl;
			}
		}
	}
}

std::vector<std::string> Parsefiles::open_file(const std::string &filename)
{
	std::ifstream in(filename);
	std::vector<std::string> file_content;
	std::string line;

	while (std::getline(in, line)) {
		file_content.push_back(line);
	}
	return (file_content);
}
