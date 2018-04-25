/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main
*/

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include "Cli.hpp"
#include <iostream>
#include "../Ipcs.hpp"
//#include "../../../include/plazza.hpp"
#include "Master.hpp"
#include "../ThreadPool.hpp"

serv_t	serv_g({0, 0, 0, 0, 0});

static void	ctrl_c(int)
{
	serv_g._status = -1;
	if (serv_g._pid > 0) {
		if (serv_g._server >= 0)
			close(serv_g._server);
	//	if (serv_g._idMem > 0)
	//		shmctl(serv_g._idMem, IPC_RMID, NULL);
	} else if (serv_g._pid == 0 && serv_g._client >= 0)
		close(serv_g._client);
	exit(0);
}

int	main(int ac, char **av)
{
	int	nbThreads = 0;
	//Ipcs	ipc;

	//ipc.initKeyMem(".", 666);
	//ipc.createSharedMem();
	serv_g._server = -1;
	serv_g._client = -1;
	serv_g._status = 0;
	serv_g._pid = 1;
	//serv_g._idMem = ipc.getIdMem();
	signal(SIGINT, ctrl_c);
	srand(time(NULL));
	if (ac != 2)
		return 84;
	nbThreads = atoi(av[1]);
	ThreadPool	*oui = new ThreadPool(nbThreads);
	s_cmdinfo *infos = new s_cmdinfo;
	oui->newInstruction(infos);
	oui->newInstruction(infos);
	delete(oui);
/* 	if (nbThreads <= 0)
		return 84;
	Master	master(nbThreads);
	master.exec(); */
	return 0;
}