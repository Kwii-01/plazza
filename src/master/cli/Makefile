##
## EPITECH PROJECT, 2018
## plazza cli
## File description:
## Makefile
##

CXX	=	g++

DEBUG	=	-g3

RM	=	rm -rf


#INC		=	-I./../../../include -I./../../tool -I./../


CXXFLAGS	=	-Wall -Wextra -Werror #$(INC)

NAME		=	plazza

SRCS	=	main.cpp		\
		Master.cpp		\
		Cli.cpp			\
		../SlaveManager.cpp	\
		../Server.cpp		\
		Parser.cpp

OBJS	=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

debug: $(OBJS)
	$(CXX) $(DEBUG) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
