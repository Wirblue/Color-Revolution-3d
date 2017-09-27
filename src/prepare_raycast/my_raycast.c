/*
** raycast.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/src
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Mon Jan  2 09:55:55 2017 mallez louis
** Last update Wed Sep 27 20:53:38 2017 
*/

#include "w3d.h"

int			pos_joueur(t_raycaster ray, t_all_player *plays)
{
  int			i;

  i = 0;
  while (i < plays->nbr)
    {
      if (ray.size > 0.05)
	{
	  if (ray.pos.x > plays->play[i].pos.x - 0.03
	      && ray.pos.x < plays->play[i].pos.x + 0.03
	      && ray.pos.y > plays->play[i].pos.y - 0.03
	      && ray.pos.y < plays->play[i].pos.y)
	    return (1);
	}
      i++;
    }
  return (0);
}


float	my_raycast_x(sfVector2f pos, float dir, t_map *map, t_raycaster *ray)
{
  sfVector2f	deltaDist;
  sfVector2f	sideDist;
  sfVector2f	rayDir;
  sfVector2i	step;
  int		side;

  rayDir.x = cosf(dir);
  rayDir.y = sinf(dir);
  deltaDist.x = sqrt(1 + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x));
  deltaDist.y = sqrt(1 + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y));
  sideDist.x = rayDir.x < 0 ? (pos.x - (int)pos.x) * deltaDist.x : ((int)pos.x + 1 - pos.x) * deltaDist.x;
  sideDist.y = rayDir.y < 0 ? (pos.y - (int)pos.y) * deltaDist.y : ((int)pos.y + 1 - pos.y) * deltaDist.y;
  step.x = rayDir.x < 0 ? -1 : 1;
  step.y = rayDir.y < 0 ? -1 : 1;
  while (((int)ray->pos.y < map->mapSize.y - 1 && (int)ray->pos.y > 0
	  && (int)ray->pos.x < map->mapSize.x - 1 && (int)ray->pos.x > 0)
	 && (map->map[(int)ray->pos.y][(int)ray->pos.x].type == 0))
    {
      if (sideDist.x < sideDist.y) {
	sideDist.x += deltaDist.x;
	ray->pos.x += step.x;
	side = 0;
      }
      else {
	sideDist.y += deltaDist.y;
	ray->pos.y += step.y;
	side = 1;
      }
    }
  ray->face = side;
  if (side == 0)
    return ((int)ray->pos.x - pos.x + (1 - step.x) / 2) / rayDir.x;
  return ((int)ray->pos.y - pos.y + (1 - step.y) / 2) / rayDir.y;
}

t_raycaster		my_raycast_wp(sfVector2f pos, float direction, t_map *map)
{
  t_raycaster		ray;
  
  ray.size = 0;
  ray.pos.x = pos.x;
  ray.pos.y = pos.y;
  ray.size = my_raycast_x(pos, direction, map, &ray);
  ray.wall = map->map[(int)ray.pos.y][(int)ray.pos.x];
  ray.inter.x = pos.x + ray.size * cosf(direction);
  ray.inter.y = pos.y + ray.size * sinf(direction);
  if (ray.wall.type == 0)
    ray.wall.type = 1;
  if (ray.face == 0)
    ray.larg = (int)((ray.inter.y - (int)ray.inter.y) * 10);
  else
    ray.larg = (int)((ray.inter.x - (int)ray.inter.x) * 10);
  return (ray);
}
