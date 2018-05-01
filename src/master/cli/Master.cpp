/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Master
*/

#include <iostream>
#include "../Server.hpp"
#include "../../tool/Error.hpp"
#include "Cli.hpp"
#include "Master.hpp"

Master::~Master()
{
}

int	Master::exec()
{
	Server	serv;

	try
	{
		serv.createServer(0);
		_data.port = serv.getPort();
		_data.addr = serv.getAddr();
		_data.socket = serv.getSocket();
		initServG();
		Cli	cli;
		cli.mainLoop(_data);
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
	serv_g._server = _data.socket;
	serv_g._client = -1;
	serv_g._pid = 1;
	serv_g._status = 0;
}
