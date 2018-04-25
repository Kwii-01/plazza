//
// EPITECH PROJECT, 2018
// comm
// File description:
// unication
//

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "Communication.hpp"

void Communication::send_message(int fd, const char *buffer)
{
	if (send(fd, buffer, strlen(buffer) + 1, 0) < 0)
		std::cout << "olala l'envoi il a pas bien marché" << std::endl;
	//write(fd, buffer.c_str(), buffer.length());
}

std::string Communication::recieve_message(int fd)
{
	char buff[1024];
	std::string buffer;
	int buffsize = 1;
	std::string final_string;

	while (buffsize > 0) {
		buffsize = recv(fd, buff, 1024, 0);
		if (buffsize < 0)
			std::cout << "olala la réception elle a pas bien chémar" << std::endl;
		buff[buffsize] = '\0';
		buffer = static_cast<std::string>(static_cast<char *>(buff));
		final_string += buffer;
	}
	return (final_string);
}
