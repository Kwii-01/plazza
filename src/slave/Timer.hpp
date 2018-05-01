/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** header
*/

#ifndef TIMER_HPP_
	#define TIMER_HPP_

#include <ctime>
#include <iostream>

class Timer {
	public:
		Timer() : _saveTime(std::time(nullptr)), _check(true) {}
		bool	checkTimer();
		void	resetTimer() { std::cout << "reset" << std::endl;
			_saveTime = std::time(nullptr); }
		void	setCheck(bool);
	private:
		time_t 	_saveTime;
		bool	_check;
};

#endif /* !TIMER_HPP_ */
