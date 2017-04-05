	##
## Makefile for bootstrap in /home/Rev/CSFML/bootstrap
## 
## Made by Roméo Nahon
## Login	 <Rev@epitech.net>
## 
## Started on	Thu Nov	10 12:12:07 2016 Roméo Nahon
## Last update	Thu Nov	10 12:12:07 2016 Roméo Nahon
##

SRC = 	main.c 		\
		error.c		\
		error_2.c	\
		draw.c		\
		display.c	\
		matchsticks.c	\
		ia.c			\

OBJ = $(SRC:.c=.o)

NAME = matchstick

##CFLAGS += -W -Wall -pedantic -ansi -Werror

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

val: $(SRC)
	gcc -g3 $(SRC) -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re: fclean all

.PHONY: $(NAME) all clean
