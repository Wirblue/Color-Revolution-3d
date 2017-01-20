##
## Makefile for d11 in /home/louis.mallez/delivery/CPool_Day12/cat
##
## Made by mallez louis
## Login   <louis.mallez@epitech.net>
##
## Started on  Tue Oct 18 15:34:14 2016 mallez louis
## Last update Fri Jan 20 11:16:02 2017 
##

SRC	=	my_src/main.c	\
		my_src/all_black.c	\
		my_src/window/open_window.c	\
		my_src/window/create_csfml.c	\
		my_src/window/event.c	\
		my_src/utilitary_fct.c	\
		my_src/prepare_raycast/boucle.c	\
		my_src/line/draw_my_line.c	\
		my_src/reader/reader.c	\
		my_src/reader/tab.c	\
		my_src/reader/verif_buff.c	\
		my_src/player/init.c	\
		my_src/player/keybind.c	\
		my_src/player/open_the_door.c	\
		my_src/line/my_put_pixel.c	\
		my_src/prepare_raycast/my_raycast.c	\
		my_src/player/my_move_forward.c	\
		my_src/other/cross_hair.c	\
		my_src/other/minimap.c	\
		my_src/other/sky_floor.c	\
		my_src/reader/texture.c		\
		my_src/victory/have_win.c	\
		my_src/victory/you_win.c	\
		my_src/reader/color.c	\
		my_src/env.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	Color_Revolution_3d

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -Iinclude/

LDFLAGS	=	-Llib/ -lmy -lmyprintf -lm -lc_graph_prog -O3

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
