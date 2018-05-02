//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "Parser.hpp"
#include "SlaveManager.hpp"
#include "Gui.hpp"

void    Gui::mainLoop(t_masterinfo &data)
{
        SlaveManager                    slv(data, 0);
        std::vector<s_cmdinfo *>        cmds;

        while (serv_g._status != -1) {
                cmds = getCmd();
                updateCmd(cmds, data);
                slv.Interpret(cmds, data);
        }
}

void    Gui::updateCmd(std::vector<s_cmdinfo *> &cmd, t_masterinfo &data)
{
        std::size_t     maxCmd = 2 * data.maxThreads;

        for (auto elem : cmd) {
                if (elem->vect_info.size() > maxCmd) {
                        std::vector<Information>        newCmd;
                        for (std::size_t i = maxCmd; i < elem->vect_info.size(); i++)
                                newCmd.push_back(elem->vect_info[i]);
                        elem->vect_info.erase(elem->vect_info.begin() + maxCmd, elem->vect_info.end());
                        s_cmdinfo  *newc = new s_cmdinfo;
                        newc->filename = elem->filename;
                        newc->vect_info = newCmd;
                        cmd.push_back(newc);
                        updateCmd(cmd, data);
                        return;
                }
        }
}

void Gui::create_window()
{
        window.create(sf::VideoMode(WIDTH_FENSTER, HEIGHT), "GUI",
                      sf::Style::Close);
}

void Gui::display_text(std::string text, int posx, int posy)
{
        sf::Text Text;

        Text.setFont(MyFont);
        Text.setString(text);
        Text.setCharacterSize(30);
        Text.setStyle(sf::Text::Bold);
        Text.setPosition(posx, posy);
        window.draw(Text);
}

void Gui::handle_events()
{
	sf::Event event;

	while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
		    exit(0);
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		        window.close();
			exit(0);
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			window.close();
		else if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode == 8 && s.length() > 0)
				s.pop_back();
			else if (event.text.unicode == 13)
				window.close();
			else
				s += static_cast<char>(event.text.unicode);
		}
	}
}

std::vector<s_cmdinfo *>        Gui::getCmd()
{
        Parser          pars;

	s = "";
	MyFont.loadFromFile("arial.ttf");
	create_window();
	window.setPosition(sf::Vector2i(0, 0));
	while (window.isOpen()) {
                window.clear();
		display_text("enter filename and information you want here", 50, 300);
		display_text(s, 0, 350);
		window.display();
		handle_events();
	}
        return pars.run(s);
}
