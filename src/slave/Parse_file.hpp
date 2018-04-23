//
// EPITECH PROJECT, 2018
// parse
// File description:
// files
//

#include <regex>
#include <vector>
#include <iostream>

#define REGEX_PHONE "0[0-9] {0,}[0-9] {0,}[0-9] {0,}[0-9] {0,}[0-9] {0,}[0-9] {0,}[0-9] {0,}[0-9] {0,}[0-9] {0,}"

class Parsefiles {
public:
	Parsefiles();
	~Parsefiles();
	std::vector<std::string> open_file(const std::string &filename);
	void parse_regex(Information information, std::vector<std::string> &file, int from, int to);
private:
	void parse_phone_regex(std::string &line, std::regex regex);
};
