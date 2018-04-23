/*
** EPITECH PROJECT, 2018
** Cli
** File description:
** source
*/

#include "Cli.hpp"
#include "Parser.hpp"
#include "SlaveManager.hpp"
#include <iostream>

void    Cli::Prompt(t_masterinfo masterinfo)
{
        std::string     input;
        Parser		parser;
        SlaveManager    manager(masterinfo);

        while (std::getline(std::cin, input)) {
                manager.Interpret(parser.run(input));
        }
}