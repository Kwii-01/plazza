/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main
*/

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include "Master.hpp"

static void	ctrl_c()
{
	serv_g.status = -1;
	if (serv_g.pid > 0) {
		if (serv_g.server >= 0)
			close(serv_g.server);
	} else if (serv_g.pid == 0 && serv_g.client >= 0)
		close(serv_data.client);}
	exit(0);
}

int	main(int ac, char **av)
{
	int	nbThreads = 0;

	serv_g.server = -1;
	serv_g.client = -1;
	serv_g.status = 0;
	serv_g.pid = 1;
	signal(SIGINT, ctrl_c);
	srand(time(NULL));
	if (ac != 2)
		return 84;
	nbThreads = atoi(av[1]);
	if (nbThreads <= 0)
		return 84;
	Master	master(nbThreads);
	return master.exec();
}