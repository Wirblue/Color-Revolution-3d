/*
** imper.c for imper in /home/louis_mallez/delivery/dante/generator
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Tue May  2 15:10:16 2017 
** Last update Tue May  9 10:09:55 2017 
*/

#include "gen.h"

int	imper_pos_link(t_map *map, t_pos *a, t_pos *b)
{
  t_vec2	npos;

  npos.x = a->x;
  npos.y = a->y;
  while (npos.y != b->y)
    {
      if (npos.y < b->y)
	npos.y++;
      else
	npos.y--;
      map->map[npos.x][npos.y].type = PATH;
    }
  while (npos.x != b->x)
    {
      if (npos.x < b->x)
	npos.x++;
      else
	npos.x--;
      map->map[npos.x][npos.y].type = PATH;
    }
  return (0);
}

int	gen_imper(t_map *map, t_pos *pos)
{
  int	i = 0;
  
  while (pos->next != NULL)
    {
      i++;
      map->map[pos->x][pos->y].type = PATH;
      imper_pos_link(map, pos, pos->next);
      pos = pos->next;
    }
  add_imper_end(map);
  return (0);
}
