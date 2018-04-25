//
// EPITECH PROJECT, 2018
// comm
// File description:
// unication
//

#include<sys/types.h>
#include<sys/socket.h>
#include <iostream>
#include "Communication.hpp"

void Communication::send_message(int server_fd, std::string buffer)
{
	if (send(server_fd, buffer.c_str(), buffer.length(), 0) < 0)
		std::cout << "olala l'envoi il a pas bien marché" << std::endl;
}

std::string Communication::recieve_message(int client_fd)
{
	void *buff= NULL;
	std::string buffer;
	int buffsize = 1;
	std::string final_string;

	while (buffsize > 0) {
		buffsize = recv(client_fd, buff, 1024, 0);
		if (buffsize < 0)
			std::cout << "olala la réception elle a pas bien chémar" << std::endl;
		buffer = static_cast<std::string>(static_cast<char *>(buff));
		buffer[buffsize] = '\0';
		final_string += buffer;
	}
	return (final_string);
}
