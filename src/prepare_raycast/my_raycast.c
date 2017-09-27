/*
** raycast.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/src
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Mon Jan  2 09:55:55 2017 mallez louis
** Last update Wed Sep 27 18:42:58 2017 
*/

#include "w3d.h"

int			find_face(t_raycaster *ray)
{
  ray->face = (FACE_X < 0) ? 1 : 2 + (FACE_Y < 0) ? 2 : 0;
  if (ray->face == 2 || ray->face == 4)
    ray->larg = (int)((ray->pos.x - (int)ray->pos.x) * 10);
  else if (ray->face == 1 || ray->face == 3)
    ray->larg = (int)((ray->pos.y - (int)ray->pos.y) * 10);
  else
    ray->larg = 255;
  return (0);
}

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
  int		side;
  sfVector2i	step;

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
  if (side == 0)
    return ((int)ray->pos.x - pos.x + (1 - step.x) / 2) / rayDir.x;
  return ((int)ray->pos.y - pos.y + (1 - step.y) / 2) / rayDir.y;
}

t_raycaster		my_raycast_wp(sfVector2f pos, float direction,
				      t_map *map, t_all_player *plays)
{
  t_raycaster		ray;
  
  ray.size = 0;
  ray.pos.x = pos.x;
  ray.pos.y = pos.y;
  ray.size = my_raycast_x(pos, direction, map, &ray);
  ray.wall = map->map[(int)ray.pos.y][(int)ray.pos.x];
  if (ray.wall.type == 0)
    ray.wall.type = 1;
  find_face(&ray);
  return (ray);
}

/*t_raycaster		my_raycast(sfVector2f pos, float direction,
				   t_bloc **map, sfVector2i mapSize)
{
  t_raycaster		ray;
  float			coss;
  float			sins;

  ray.size = 0;
  ray.pos.x = pos.x;
  ray.pos.y = pos.y;
  coss = cosf(direction);
  sins = sinf(direction);
   while (((int)ray.pos.y < mapSize.y - 1 && (int)ray.pos.y > 0
      && (int)ray.pos.x < mapSize.x - 1 && (int)ray.pos.x > 0)
      && (map[(int)ray.pos.y][(int)ray.pos.x].type == 0)
      && ray.size < R_DIST)
      {
      ray.size = ray.size + PRECISION;
      ray.pos.x = pos.x + ray.size * coss;
      ray.pos.y = pos.y + ray.size * sins;
      }
  ray.size = my_raycast_x(pos, direction, map, &ray);
  ray.wall = map[(int)ray.pos.y][(int)ray.pos.x];
  if (ray.wall.type == 0)
    ray.wall.type = 1;
  find_face(&ray);
  return (ray);
  }*/
