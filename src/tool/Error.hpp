/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Error
*/

#ifndef ERROR_HPP_
	#define ERROR_HPP_

#include <exception>
#include <string>

namespace Err
{
	class Error :	public std::exception
	{
		public:
			Error(const std::string &message) : _message(message) {}
			~Error() {}
			virtual const char	*what() const noexcept {
				return _message.data();
			}
		private:
			std::string	_message;
	};

	class ServerError	:	public Error
	{
		public:
			ServerError(const std::string &mess) : Error(mess) {}
	};

	class FileError	:	public Error
	{
		public:
			FileError(const std::string &mess) : Error(mess) {}
	};

	class ParseError	:	public Error
	{
		public:
			ParseError(const std::string &mess) : Error(mess) {}
	};
};

#endif /* !ERROR_HPP_ */
