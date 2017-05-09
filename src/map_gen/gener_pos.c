/*
** gener_pos.c for gener_pos in /home/louis_mallez/delivery/dante/generator/src
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Tue May  2 14:29:45 2017 
** Last update Tue May  9 10:10:18 2017 
*/

#include "gen.h"

int	add_pos(int x, int y, t_pos **pos)
{
  t_pos	*new;

  if ((new = malloc(sizeof(t_pos))) == NULL)
    exit_we(84, "Error malloc\n");
  new->x = x;
  new->y = y;
  new->next = (*pos);
  (*pos) = new;
  return (0);
}

int	swap_pos(t_pos *pos, t_pos *next)
{
  t_pos	temp;

  temp.x = pos->x;
  temp.y = pos->y;
  pos->x = next->x;
  pos->y = next->y;
  next->x = temp.x;
  next->y = temp.y;
  return (0);
}

t_pos	*sort_pos(t_pos *pos)
{
  int	swap;
  t_pos	*start;

  start = pos;
  swap = 1;
  while (swap != 0)
    {
      swap = 0;
      while (pos->next != NULL)
	{
	  if (pos->x + pos->y < pos->next->x + pos->next->y)
	    {
	      swap_pos(pos, pos->next);
	      swap++;
	    }
	  pos = pos->next;
	}
      pos = start;
    }
  return (pos);
}

t_pos	*first_pass(t_map *map)
{
  int	nbr_pos;
  t_pos	*pos;

  pos = NULL;
  if ((nbr_pos = (map->mapSize.x * map->mapSize.y) / PROB) == 0)
    nbr_pos = 1;
  add_pos(1, 1, &pos);
  while (nbr_pos > 0)
    {
      add_pos(rand() % (map->mapSize.x - 2) + 1,
	      rand() % (map->mapSize.y - 2) + 1, &pos);
      nbr_pos--;
    }
  add_pos(map->mapSize.x - 2, map->mapSize.y - 2, &pos);
  pos = sort_pos(pos);
  return (pos);
}
