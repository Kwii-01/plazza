/*
** EPITECH PROJECT, 2018
** Cli
** File description:
** header
*/

#ifndef GUI_HPP_
	#define GUI_HPP_

#include <SFML/Graphics.hpp>
#include "plazza.hpp"

#define WIDTH_FENSTER 900
#define HEIGHT 1000

extern serv_t	serv_g;

class Gui
{
	public:
		Gui() {}
		~Gui() {}
		void	mainLoop(t_masterinfo &);
	private:
		void handle_events();
		void create_window();
		void display_text(std::string text, int posx, int posy);
		void	updateCmd(std::vector<s_cmdinfo *> &, t_masterinfo &);
		std::vector<s_cmdinfo *>	getCmd();
		sf::RenderWindow window;
		sf::Font MyFont;
		sf::String text;
		std::string     s;
};

#endif /* !GUI_HPP_ */
