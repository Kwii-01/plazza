/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main
*/

#include <stdlib.h>
#include "Master.hpp"
#include "Cli.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	int	nbThreads = 0;

	if (ac != 2)
		return 84;
	nbThreads = atoi(av[1]);
	if (nbThreads <= 0)
		return 84;
	Master	master(nbThreads);
	master.exec();
	t_masterinfo	info = {0, 0, 0, 0};
	Cli	cli(info);
	cli.Prompt();
	return 0;
}