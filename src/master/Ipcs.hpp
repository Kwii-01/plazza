/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Ipcs
*/

#ifndef IPCS_HPP_
	#define IPCS_HPP_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

class Ipcs {
	public:
		Ipcs() : _keyMem(-1), _idMem(-1), _fd(nullptr) {}
		~Ipcs() { shmctl(_idMem, IPC_RMID, NULL); }
		void	initKeyMem(char *, int);
		void	createSharedMem();
		int	getIdMem() const noexcept { return _idMem; }
		int	*getFd() const noexcept { return _fd; }
	private:
		key_t	_keyMem;
		int	_idMem;
		int	*_fd;
};

#endif /* !IPCS_HPP_ */
