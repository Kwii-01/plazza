/*
x** EPITECH PROJECT, 2018
** plazza
** File description:
** plazza's header
*/

#ifndef PLAZZA_HPP_
	#define PLAZZA_HPP_

#include <string>
#include <vector>

enum Information
{
	PHONE_NUMBER,
	EMAIL_ADDRESS,
	IP_ADDRESS
};

struct t_masterinfo
{
	unsigned long int	addr;
	int			socket;
	int			port;
	int			maxThreads;
};

struct t_informations
{
	std::string str;
	Information value;
};

struct s_cmdinfo
{
        std::string filename;
	std::vector<Information> vect_info;
};

#endif /* !PLAZZA_HPP_ */
