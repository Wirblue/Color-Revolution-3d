##
## Makefile for d11 in /home/louis.mallez/delivery/CPool_Day12/cat
##
## Made by mallez louis
## Login   <louis.mallez@epitech.net>
##
## Started on  Tue Oct 18 15:34:14 2016 mallez louis
## Last update Tue May  9 10:10:46 2017 
##

SRC	=	src/main.c	\
		src/all_black.c	\
		src/window/open_window.c	\
		src/window/create_csfml.c	\
		src/window/event.c	\
		src/utilitary_fct.c	\
		src/prepare_raycast/boucle.c	\
		src/line/draw_my_line.c	\
		src/reader/reader.c	\
		src/reader/tab.c	\
		src/reader/verif_buff.c	\
		src/player/init.c	\
		src/player/keybind.c	\
		src/player/open_the_door.c	\
		src/line/my_put_pixel.c	\
		src/prepare_raycast/my_raycast.c	\
		src/player/my_move_forward.c	\
		src/other/cross_hair.c	\
		src/other/minimap.c	\
		src/other/sky_floor.c	\
		src/reader/texture.c		\
		src/victory/have_win.c	\
		src/victory/you_win.c	\
		src/reader/color.c	\
		src/env.c	\
		src/map_gen/check_around.c	\
		src/map_gen/imper_add_end.c	\
		src/map_gen/map.c	\
		src/map_gen/utils.c	\
		src/map_gen/imper.c	\
		src/map_gen/gener_pos.c	\
		src/map_gen/map_gen.c	\

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
