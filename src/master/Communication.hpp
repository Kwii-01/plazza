//
// EPITECH PROJECT, 2018
// comm
// File description:
// hpp
//

#ifndef COM_HPP_
	# define COM_HPP_

class Communication
{
	public:
		void send_message(int server_fd, const char *buffer);
		std::string recieve_message(int client_fd);
};

#endif