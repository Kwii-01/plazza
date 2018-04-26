/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** internet socket
*/

#ifndef INTSOCKET_HPP_
	#define INTSOCKET_HPP_

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

class IntSocket {
	public:
		IntSocket() {};
		~IntSocket() {};
		int	intSocket(int, int, int);
		int	intBind(int, const struct sockaddr *, socklen_t);
		int	intListen(int, int);
		int	intClose(int);
		int	intConnect(int, const struct sockaddr *, socklen_t);
		int	intAccept(int, struct sockaddr *, socklen_t *);
};

#endif /* !INTSOCKET_HPP_ */
