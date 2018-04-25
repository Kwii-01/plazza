/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Ipcs
*/

#include "../tool/Error.hpp"
#include "Ipcs.hpp"

void	Ipcs::createSharedMem()
{

	_idMem = shmget(_keyMem, sizeof(int *), SHM_R | SHM_W);
	if (_idMem == -1) {
		_idMem = shmget(_keyMem, sizeof(int *), IPC_CREAT | SHM_R | SHM_W);
		if (_idMem < 0)
			throw Err::Error("Couldn't create the shared memory.");
		_fd = (int *)shmat(_idMem, NULL, SHM_R | SHM_W);
	} else
		_fd = (int *)shmat(_idMem, NULL, SHM_R | SHM_W);
}

void	Ipcs::initKeyMem(char *file, int id)
{
	_keyMem = ftok(file, id);
	if (_keyMem == -1)
		throw Err::Error("Couldn't create ipcs.");
}