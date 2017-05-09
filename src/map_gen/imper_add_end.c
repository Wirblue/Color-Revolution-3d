/*
** imper_add_end.c for aled in /home/louis_mallez/delivery/dante/generator
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Tue May  2 16:21:41 2017 
** Last update Tue May  9 10:06:50 2017 
*/

#include "gen.h"
  
int		imper_end(t_map *map)
{
  t_pos		pos;
  int		i;
  t_pos		*to;

  i = 0;
  to = NULL;
  pos.x = rand() % (map->mapSize.x - 2) + 1;
  pos.y = rand() % (map->mapSize.y - 2) + 1;
  map->map[pos.x][pos.y].type = -1;
  while (to == NULL)
    {
      to = check_around(map, pos, i);
      i++;
    }
  map->map[pos.x][pos.y].type = PATH;
  imper_pos_link(map, &pos, to);
  return (0);
}

int	add_imper_end(t_map *map)
{
  int	nbr_end;

  nbr_end = map->mapSize.x * map->mapSize.y / PROBEND;
  while (nbr_end > 0)
    {
      imper_end(map);
      nbr_end--;
    }
  return (0);
}
