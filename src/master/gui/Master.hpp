/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** master's header
*/

#ifndef MASTER_HPP_
	#define MASTER_HPP_

extern serv_t   serv_g;

class   Master
{
        public:
        Master(int nbthread, int gui) : _data({0, -1, -1, nbthread}), _gui(gui) {}
                ~Master();
                int     exec();
        private:
                t_masterinfo    _data;
                int _gui;

                void    initServG();
};

#endif /* !MASTER_HPP_ */
