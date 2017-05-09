/*
** map.c for gen in /home/louis_mallez/delivery/dante/generator
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Tue May  2 14:55:40 2017 
** Last update Tue May  9 10:07:01 2017 
*/

#include "gen.h"

int	init_map(t_map *map)
{
  int	cp_x;
  int	cp_y;

  if ((map->map = malloc(map->mapSize.x * sizeof(t_bloc *))) == NULL)
    exit_we(84, "Error malloc\n");
  cp_x = 0;
  while (cp_x < map->mapSize.x)
    {
      if ((map->map[cp_x] = malloc(map->mapSize.y * sizeof(t_bloc))) == NULL)
        exit_we(84, "Error malloc\n");
      cp_y = 0;
      while (cp_y < map->mapSize.y)
	{
	  map->map[cp_x][cp_y].type = WALL;
	  map->map[cp_x][cp_y].color = 0;
	  cp_y++;
	}
      cp_x++;
    }
  return (0);
}
