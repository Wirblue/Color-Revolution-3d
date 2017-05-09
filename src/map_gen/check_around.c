/*
** checl_around.c for around in /home/louis_mallez/delivery/dante/generator
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Tue May  2 16:46:28 2017 
** Last update Tue May  9 10:06:26 2017 
*/

#include "gen.h"

t_pos	*check_4_border(t_map *map, t_pos *pos, int range, int i)
{
  t_pos	*temp;

  if (pos->x < 0 || pos->y < 0 || pos->x >= map->mapSize.x
      || pos->y >= map->mapSize.y)
    return (NULL);
  if (map->map[pos->x][pos->y].type == PATH)
    return (pos);
  temp = malloc(sizeof(t_pos));
  if (i >= range)
    return (NULL);
  pos->x = pos->x + 1;
  if ((temp = check_4_border(map, pos, range, i + 1)) != NULL)
    return (temp);
  pos->x = pos->x - 2;
  if ((temp = check_4_border(map, pos, range, i + 1)) != NULL)
    return (temp);
  pos->x = pos->x - 1;
  pos->y = pos->y + 1;
  if ((temp = check_4_border(map, pos, range, i + 1)) != NULL)
    return (temp);
  pos->y = pos->y - 2;
  if ((temp = check_4_border(map, pos, range, i + 1)) != NULL)
    return (temp);
  pos->y = pos->y + 1;
  free(temp);
  return (NULL);
}

t_pos   *check_around(t_map *map, t_pos pos, int range)
{
  t_pos	*temp;

  if ((temp = malloc(sizeof(t_pos))) == NULL)
    exit_we(84, "Error malloc\n");
  temp->x = pos.x;
  temp->y = pos.y;
  temp = check_4_border(map, temp, range, 0);
  return (temp);
}
