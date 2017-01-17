/*
** move_forward.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/src
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Tue Jan  3 13:28:45 2017 mallez louis
** Last update Fri Jan 13 17:41:15 2017 
*/

#include "w3d.h"

sfVector2f	mmove_forward(sfVector2f pos, float direction, float distance,
			      t_map *map)
{
  if (((int)(pos.y + sin(direction) * distance) < 0 ||
       (int)(pos.y + sin(direction) * distance) > map->mapSize.y - 1 ||
       (int)(pos.x + sin(direction) * distance) < 0 ||
       (int)(pos.y + sin(direction) * distance > map->mapSize.x - 1)) ||
      (map->map[(int)(pos.y + sin(direction) * distance)]
       [(int)(pos.x + cos(direction) * distance)].type != 0))
    return (pos);
  pos.x = pos.x + cos(direction) * distance;
  pos.y = pos.y + sin(direction) * distance;
  return (pos);
}
