//
// EPITECH PROJECT, 2018
// parse
// File description:
// file
//

#include <fstream>
#include "plazza.hpp"
#include "Parse_file.hpp"

Parsefiles::~Parsefiles()
{
}

Parsefiles::Parsefiles()
{
}

void Parsefiles::parse_phone_regex(std::string &line, std::regex regex)
{
	if (std::regex_match(line, regex) == 1)
		std::cout << line << std::endl;
}

void Parsefiles::parse_regex(Information information, std::vector<std::string> &file, int from, int to)
{
	std::string substr;
	int current = 0;
	for (auto line : file) {
		current++;
		if (current - 1 < from || current - 1 > to)
			continue ;
		std::istringstream stream(line);
		if (information == EMAIL_ADDRESS)
			substr = "[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+";
		else if (information == IP_ADDRESS)
			substr = "[0-255].[0-255].[0-255].[0-255]";
		else
			substr = REGEX_PHONE;
		std::regex regex(substr.c_str());
		if (information == PHONE_NUMBER)
			parse_phone_regex(line, regex);
		else {
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
