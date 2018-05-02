/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** header
*/

#ifndef SLAVEMANAGER_HPP_
	#define SLAVEMANAGER_HPP_

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "plazza.hpp"

#define WIDTH_FENSTER 1000
#define HEIGHT 1000

extern serv_t	serv_g;

class SlaveManager {
	public:
		SlaveManager(t_masterinfo masterinfo, int gui) : _masterinfo(masterinfo), _gui(gui) {}
		void	Interpret(std::vector<s_cmdinfo *> &, t_masterinfo &);
	private:
	void print_threads(const std::string &filename, int nbr_max, int line);
		void display_text(std::string text, int posx, int posy);
		void	create_window();
		int	checkFreeToWork();
		void	checkWhoIsNotWorking();
		void	CreateSlave(s_cmdinfo info, t_masterinfo);
		void	DeleteSlave();
		void	AssignWorks(t_client &, s_cmdinfo &);
		std::vector<t_client>	_clients;
		t_masterinfo		_masterinfo;
		TTF_Font* _arial;
		SDL_Window *window;
		SDL_Renderer *render;
		int _gui;
};

#endif /* !SLAVEMANAGER_HPP_ */
