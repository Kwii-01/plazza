/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** source
*/

#include "Timer.hpp"
#include <iostream>

void	Timer::setCheck(bool statu) {
        if (statu == true)
                resetTimer();
        _check = statu;
}

bool	Timer::checkTimer()
{
        if (_check == false)
                return (_check);
       // std::cout << "time  = " << std::time(nullptr) - _saveTime << std::endl;
	if ((std::time(nullptr) - _saveTime) > 5)
		return (true);
	return (false);
}
