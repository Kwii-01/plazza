/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main
*/

#include "SDL2/SDL.h"
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <exception>
#include "Gui.hpp"
#include <iostream>
#include "Master.hpp"
#include "../ThreadPool.hpp"

serv_t	serv_g({0, 0, 0, 0, 0});

static void     ctrl_c(int)
{
        serv_g._status = -1;
        if (serv_g._pid > 0) {
                if (serv_g._server >= 0)
                        close(serv_g._server);
        } else if (serv_g._pid == 0 && serv_g._client >= 0)
                close(serv_g._client);
        exit(0);
}

int	main(int ac, char **av)
{
	int	nbThreads = 0;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0)
		return (84);
	signal(SIGINT, ctrl_c);
        srand(time(NULL));
	if (ac != 2)
		return 84;
	nbThreads = atoi(av[1]);
	if (nbThreads <= 0)
		return 84;
	Master	master(nbThreads, true);
	master.exec();
	SDL_Quit();
	return 0;
}
