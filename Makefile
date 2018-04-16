##
## EPITECH PROJECT, 2018
## plazza
## File description:
## Makefile
##

CXX	=	g++

DEBUG	=	-g3

RM	=	rm -rf

INC		=	-I./include

CXXFLAGS	=	-Wall -Wextra -Werror $(INC)

NAME		=	plazza

SRCS_GUI	=	src/master/gui/main.cpp		\
			src/master/gui/Master.cpp

SRCS_CLI	=	src/master/cli/main.cpp		\
			src/master/cli/Master.cpp

OBJS_GUI	=	$(SRCS_GUI:.cpp=.o)

OBJS_CLI	=	$(SRCS_CLI:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS_CLI)
	$(CXX) $(CXXFLAGS) $(OBJS_CLI) -o $(NAME)

ui:	 $(OBJS_GUI)
	$(CXX) $(CXXFLAGS) $(OBJS_GUI) -o $(NAME)

clean:
	$(RM) $(OBJS_CLI)
	$(RM) $(OBJS_GUI)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all ui clean fclean re