/*
** raycast.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/src
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Mon Jan  2 09:55:55 2017 mallez louis
** Last update Sun Jan 15 20:43:07 2017 
*/

#include "w3d.h"

int			find_face(t_raycaster *ray)
{
  ray->face = 0;
  if (FACE_X < 0 && FACE_Y >= 0)
    ray->face = 1;
  if (FACE_X >= 0 && FACE_Y > 0)
    ray->face = 2;
  if (FACE_X <= 0 && FACE_Y <= 0)
    ray->face = 4;
  if (FACE_X > 0 && FACE_Y < 0)
    ray->face = 3;
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

t_raycaster		my_raycast_wp(sfVector2f pos, float direction,
				      t_map *map, t_all_player *plays)
{
  t_raycaster		ray;

  ray.size = 0;
  ray.pos.x = pos.x;
  ray.pos.y = pos.y;
  while (((int)ray.pos.y < map->mapSize.y - 1 && (int)ray.pos.y > 0
	  && (int)ray.pos.x < map->mapSize.x - 1 && (int)ray.pos.x > 0)
	 && (map->map[(int)ray.pos.y][(int)ray.pos.x].type == 0)
	 && ray.size < R_DIST
	 && pos_joueur(ray, plays) != 1)
    {
      ray.size = ray.size + PRECISION;
      ray.pos.x = pos.x + ray.size * cosf(direction);
      ray.pos.y = pos.y + ray.size * sinf(direction);
    }
  ray.wall = map->map[(int)ray.pos.y][(int)ray.pos.x];
  if (ray.wall.type == 0)
    ray.wall.type = 1;
  find_face(&ray);
  return (ray);
}

t_raycaster		my_raycast(sfVector2f pos, float direction,
				   t_bloc **map, sfVector2i mapSize)
{
  t_raycaster		ray;

  ray.size = 0;
  ray.pos.x = pos.x;
  ray.pos.y = pos.y;
  while (((int)ray.pos.y < mapSize.y - 1 && (int)ray.pos.y > 0
	  && (int)ray.pos.x < mapSize.x - 1 && (int)ray.pos.x > 0)
	 && (map[(int)ray.pos.y][(int)ray.pos.x].type == 0)
	 && ray.size < R_DIST)
    {
      ray.size = ray.size + PRECISION;
      ray.pos.x = pos.x + ray.size * cosf(direction);
      ray.pos.y = pos.y + ray.size * sinf(direction);
    }
  ray.wall = map[(int)ray.pos.y][(int)ray.pos.x];
  if (ray.wall.type == 0)
    ray.wall.type = 1;
  find_face(&ray);
  return (ray);
}
