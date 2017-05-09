/*
** main.c for gen in /home/louis_mallez/delivery/dante/generator/src
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Tue May  2 14:28:26 2017 
** Last update Tue May  9 10:05:34 2017 
*/

#include "gen.h"

int	map_gen(t_map *map)
{
  t_pos	*pos;

  srand(getpid());
  if ((map->mapSize.x = MAP_GEN_X) <= 0 || (map->mapSize.y = MAP_GEN_Y) <= 0)
    exit_we(84, "Error invalid size\n");
  init_map(map);
  pos = first_pass(map);
  gen_imper(map, pos);
  map->map[1][1].type = 'p' - 48;
  return (0);
}
