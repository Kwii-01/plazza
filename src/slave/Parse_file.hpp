//
// EPITECH PROJECT, 2018
// parse
// File description:
// files
//

#include <regex>
#include <vector>
#include <iostream>

class Parsefiles {
public:
	Parsefiles();
	~Parsefiles();
	std::vector<std::string> open_file(const std::string &filename);
	void parse_regex(Information information, std::vector<std::string> &file, int from, int to);
private:
	void check_if_match(std::string str, int x, int count);
	void parse_phone(std::string &line);
};
