##
## Makefile for d11 in /home/louis.mallez/delivery/CPool_Day12/cat
##
## Made by mallez louis
## Login   <louis.mallez@epitech.net>
##
## Started on  Tue Oct 18 15:34:14 2016 mallez louis
## Last update Thu Dec 15 15:05:46 2016 mallez louis
##

SRC	=

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

NAME	=	bsq

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -Iinclude/

LDFLAGS	=	-Llib/ -lmy -lmyprintf

all:	 $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

o:	all clean

.PHONY: all clean fclean re o
