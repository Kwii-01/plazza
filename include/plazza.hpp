/*
x** EPITECH PROJECT, 2018
** plazza
** File description:
** plazza's header
*/

#ifndef	PLAZZA_HPP_
	# define PLAZZA_HPP_

#include <string>
#include <vector>

enum Information
{
	PHONE_NUMBER,
	EMAIL_ADDRESS,
	IP_ADDRESS
};

struct t_masterinfo {
	uint32_t	addr;
	int			socket;
	int			port;
	int			maxThreads;
};

struct t_informations {
	std::string str;
	Information value;
};

struct s_cmdinfo {
	std::string filename;
	std::vector<Information> vect_info;
};

struct	t_client
{
	pid_t	pid;
	int	fd;
	bool	working;
};

struct serv_t {
	int	_server;
	int	_client;
	int	_pid;
	int	_status;
};

struct threads_info {
	int	id;
	std::vector<std::string>	file;
	int	start;
	int	end;
}

#endif /* !PLAZZA_HPP_ */
