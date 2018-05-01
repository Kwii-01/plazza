##
## EPITECH PROJECT, 2018
## plazza
## File description:
## Makefile
##

RM	=	rm -rf

NAME	=	plazza

all: 
	make -C ./src/master/cli
	mv ./src/master/cli/$(NAME) .

ui: 
	make -C ./src/master/gui
	mv ./src/master/gui/$(NAME) .

clean:
	make clean -C ./src/master/cli
	make clean -C ./src/master/gui

fclean: clean
	$(RM) $(NAME)

reui : fclean ui

re: fclean all

.PHONY: all ui clean fclean re
