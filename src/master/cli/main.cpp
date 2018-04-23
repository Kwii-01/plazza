/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main
*/

#include <stdlib.h>
#include <time.h>
#include "Master.hpp"

int	main(int ac, char **av)
{
	int	nbThreads = 0;

	srand(time(NULL));
	if (ac != 2)
		return 84;
	nbThreads = atoi(av[1]);
	if (nbThreads <= 0)
		return 84;
	Master	master(nbThreads);
	return master.exec();
}