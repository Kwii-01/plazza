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

void Parsefiles::parse_phone(std::string &s)
{
	std::ofstream out;

	 out.open("log", std::ios::app);
	 out << s << "\n";
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
			substr = "(?:(?:\\+|00)33|0)\\s*[1-9](?:[\\s.-]*\\d{2}){4}";
		else if (information == EMAIL_ADDRESS)
			substr = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
		else if (information == IP_ADDRESS)
			substr = "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}";
		std::regex words_regex(substr.c_str());
		auto words_begin =
			std::sregex_iterator(line.begin(), line.end(), words_regex);
		auto words_end = std::sregex_iterator();
		for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
			std::smatch match = *i;
			std::string match_str = match.str();
			std::cout << match_str << '\n';
			parse_phone(match_str);
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
