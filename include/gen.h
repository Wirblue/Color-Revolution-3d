/*
** gen.h for gen in /home/louis_mallez/delivery/dante/generator
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Tue May  2 14:31:37 2017 
** Last update Tue May  9 10:17:09 2017 
*/

#ifndef GEN_H_
#define GEN_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "w3d.h"

typedef enum
  {
    block,
    empty,
    path,
    dead,
  }     STATE;

typedef struct	s_vec2
{
  int		x;
  int		y;
}		t_vec2;

typedef struct	s_pos
{
  int		x;
  int		y;
  struct s_pos	*next;
}		t_pos;

#define PROB 200
#define PROBEND 3

#define MAP_GEN_X 15
#define MAP_GEN_Y 15

#define WALL rand() % 9
#define PATH '0' - 48

#define MLAB map->lab

void	exit_we(int, char *);
int	init_map(t_map *);
t_pos	*first_pass(t_map *);
int	gen_imper(t_map *, t_pos *);
int	add_imper_end(t_map *);
t_pos	*check_around(t_map *, t_pos, int);
int	imper_pos_link(t_map *, t_pos *, t_pos *);

#endif /* GEN_H_ */
