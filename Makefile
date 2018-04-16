##
## EPITECH PROJECT, 2018
## plazza
## File description:
## Makefile
##

CXX	=	g++

DEBUG	=	-g3

RM	=	rm -rf

CXXFLAGS	+=	-Wall -Wextra -Werror

NAME	=	plazza

SRCS	=	src/main.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

ui: $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) #flag lib graphique

debug: $(OBJS)
	$(CXX) $(DEBUG) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PONY:	all clean fclean re