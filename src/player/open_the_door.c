/*
** open_the_door.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/player
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Thu Jan  5 12:35:48 2017 mallez louis
** Last update Sun Jan 15 20:23:27 2017 
*/

#include "w3d.h"

int		pose_bloc(t_player *play, t_map *map)
{
  t_raycaster	ray;

  ray = my_raycast(play->pos, play->angle, map->map, map->mapSize);
  if (ray.wall.type == 8 && ray.size <= 2)
    {
      map->map[(int)ray.pos.y][(int)ray.pos.x].type = 0;
      play->bloc++;
    }
  else if (ray.size > 2.1 &&
	   map->map[(int)(play->pos.y  + sinf(play->angle * 2))]
	   [(int)(play->pos.x + cosf(play->angle) * 2)].type == 0
	   && play->bloc > 0)
    {
      map->map[(int)(play->pos.y + sinf(play->angle) * 2)]
	[(int)(play->pos.x + cosf(play->angle) * 2)].type = 8;
      play->bloc--;
    }
  return (0);
}

int		open_the_door(t_player *play, t_map *map)
{
  t_raycaster	ray;

  ray = my_raycast(play->pos, play->angle, map->map, map->mapSize);
  if (ray.wall.color >= 0 && ray.wall.color < 9)
    map->map[(int)ray.pos.y][(int)ray.pos.x].color = ray.wall.color + 1;
  else if (ray.wall.color == 9)
    map->map[(int)ray.pos.y][(int)ray.pos.x].color = 0;
  return (0);
}
