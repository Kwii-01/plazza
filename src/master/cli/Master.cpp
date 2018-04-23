/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Master
*/

#include <iostream>
#include "Server.hpp"
#include "Error.hpp"
#include "Master.hpp"

Master::~Master()
{
}

int	Master::exec()
{
	try
	{
		Server	serv;

		serv.createServer(0);
		_data.port = serv.getPort();
		_data.addr = serv.getAddr();
		_data.server = serv.getSocket();
		initServG();
		//--> execution de la boucle principale
		serv.closeServer();
	} catch (Err::Error &e) {
		serv.closeServer();
		std::cerr << e.what() << std::endl;
		return 84;
	}
	return 0;
}

void	Master::initServG()
{
	serv_g.server = _data.server;
	serv_g.client = -1;
	serv_g.pid = 1;
	serv_g.status = 0;
}