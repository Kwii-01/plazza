/*
** EPITECH PROJECT, 2018
** plazza source
** File description:
** 
*/

#include <iostream>
#include "Server.hpp"
#include "SlaveManagergui.hpp"
#include "Slave.hpp"
#include "Error.hpp"
#include "IntSocket.hpp"
#include <thread>
#include <fstream>

int	SlaveManager::checkFreeToWork()
{
	std::size_t to_return = -1;

	for (std::size_t i = 0; i < _clients.size(); ++i) {
		if (_clients[i].working == false) {
			to_return = i;
		}
	}
	return to_return;
}

void SlaveManager::print_threads(const std::string &filename, int nbr_max, int line)
{
	std::ifstream file(filename);
	std::string useless;
	int lines = 0;
	
	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, useless);
			lines++;
		}
	}
	if (lines > nbr_max) {
		int x = 52;
		for (int inc = 0; inc < nbr_max; inc++) {
			SDL_Rect rect = {x, line, 25, 25};
			SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
                        SDL_RenderFillRect(render, &rect);
			x+= 27;
			if (x > 500) {
				x = 52;
				line +=	26;
			}
		}
	}
	else {
		int x = 52;
                for (int inc = 0; inc < nbr_max; inc++) {
                        SDL_Rect rect = {x, line, 25, 25};
			if (inc < lines)
				SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
			else
				SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
                        SDL_RenderFillRect(render, &rect);
                        x+= 27;
                        if (x > 500) {
                                x = 52;
                                line += 26;
                        }
                }
	}
}

void    SlaveManager::Interpret(std::vector<s_cmdinfo *> &cmd_info, t_masterinfo &masterinfo)
{
	int	reassign = -1;
	int x = 0;

	create_window();
	checkWhoIsNotWorking();
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);
	for (auto info : cmd_info) {
		std::cout << x << std::endl;
		SDL_Rect rect = {0, x, 50, 50};
		if (!(_clients.empty())) {
			reassign = checkFreeToWork();
			SDL_SetRenderDrawColor(render, 100, 100, 100, 100);
                        SDL_RenderDrawRect(render, &rect);
			SDL_RenderFillRect(render, &rect);
			print_threads(info->filename, masterinfo.maxThreads, x);
		}
		if (reassign >= 0) {
			AssignWorks(_clients[reassign], *info);
			SDL_SetRenderDrawColor(render, 100, 100, 100, 100);
                        SDL_RenderDrawRect(render, &rect);
			SDL_RenderFillRect(render, &rect);
			print_threads(info->filename, masterinfo.maxThreads, x);
		}
		else {
			CreateSlave(*info, masterinfo);
			SDL_SetRenderDrawColor(render, 200, 200, 200, 200);
                        SDL_RenderDrawRect(render, &rect);
			SDL_RenderFillRect(render, &rect);
			print_threads(info->filename, masterinfo.maxThreads, x);
		}
		x += 55;
	}
	SDL_RenderPresent(render);
        SDL_Delay(5000);
	if (!(cmd_info.empty()))
		cmd_info.clear();
	SDL_DestroyWindow(window);
	SDL_CloseAudio();
}

void SlaveManager::display_text(std::string text, int posx, int posy)
{
	SDL_Color White = {255, 255, 255, 0};
        SDL_Surface *surface = TTF_RenderText_Solid(_arial, text.c_str(), White);
        SDL_Texture *text_message = SDL_CreateTextureFromSurface(render, surface);
        SDL_Rect place;

        place.x = posx;
        place.y = posy;
        place.w = 20 * text.length();
	place.h = 20;
        SDL_RenderCopy(render, text_message, NULL, &place);
}

void	SlaveManager::AssignWorks(t_client &client, s_cmdinfo &info)
{
	IntSocket	iSock;
	int		i[1];

	if (iSock.intRecv(client.fd, i, sizeof(i), 0) == -1)
		throw Err::Error("Recv failed!!");
	if (i[0] == 0 && !client.working) {
		if (iSock.intSend(client.fd, &info, sizeof(info), 0) == -1)
			throw Err::Error("Send failed");
		client.working = true;
	}
}

void	SlaveManager::checkWhoIsNotWorking()
{
	IntSocket	iSock;
	int		i[1];

	for (auto slave : _clients) {
		iSock.intRecv(slave.fd, i, sizeof(int), 0);
		if (i[0] == 0)
			slave.working = false;
	}
}

void SlaveManager::create_window()
{
	window = SDL_CreateWindow("sdl2!", 1000, 0, 500, 500, SDL_WINDOW_SHOWN);
        if (window == NULL)
		exit(0);
        TTF_Init();
        _arial = TTF_OpenFont("arial.ttf", 20);
        render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void	SlaveManager::CreateSlave(s_cmdinfo info, t_masterinfo masterinfo)
{
	Slave		slave;
	Server		serv;
	IntSocket	iSock;
	t_client	client;
	serv_g._pid = fork();

	if (serv_g._pid > 0) {
		serv_g._client = serv.acceptClient(serv_g._server);
		client.pid = serv_g._pid;
		client.fd = serv_g._client;
		client.working = false;
		/*int lol[1];
		iSock.intRecv(client.fd, lol, sizeof(lol), 0);
		if (lol[0] == 0)
			std::cout << "JE VAIS TRAVAILLER" << std::endl;
		iSock.intSend(client.fd, &info, sizeof(info), 0);*/
		AssignWorks(client, info);
		_clients.push_back(client);
	}
	if (serv_g._pid == 0) {
		serv_g._client = slave.connectServer(masterinfo);
		slave.run();
		close(slave.getSocket());
		exit(0);
	}
}

void	SlaveManager::DeleteSlave()
{

}
