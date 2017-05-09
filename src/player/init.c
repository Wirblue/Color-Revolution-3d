/*
** init.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/player
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Tue Jan  3 13:50:44 2017 mallez louis
** Last update Fri Feb  3 20:07:02 2017 
*/

#include "w3d.h"

int		count_player(t_map *map)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  y = 0;
  while (y != map->mapSize.y - 1)
    {
      x = 0;
      while (x != map->mapSize.x - 1)
	{
	  if (map->map[y][x].type == 64)
	    i++;
	  x++;
	}
      y++;
    }
  return (i);
}

t_player	setup_player(sfVector2i pos, t_map *map)
{
  t_player	play;

  play.pos.x = pos.x + 0.5;
  play.pos.y = pos.y + 0.5;
  play.angle = 0;
  map->map[pos.y][pos.x].type = 0;
  return (play);
}

int		init_player(t_map *map, t_all_player *plays)
{
  sfVector2i	pos;
  int		p;

  p = 0;
  pos.y = 0;
  plays->nbr = count_player(map);
  if (plays->nbr < 0 || plays->nbr > 9)
    return (failed_we("CR3D:\tToo much or too few players\n", -1));
  if ((plays->play = malloc(plays->nbr * sizeof(t_player))) == NULL)
    return (failed_we("CR3D:\terror malloc\n", -1));
  while (pos.y != map->mapSize.y - 1)
    {
      pos.x = 0;
      while (pos.x != map->mapSize.x - 1)
	{
	  if (map->map[pos.y][pos.x].type == 64)
	    {
	      plays->play[p] = setup_player(pos, map);
	      p++;
	    }
	  pos.x++;
	}
      pos.y++;
    }
  return (0);
}

int		move_turn(t_player *play, float a)
{
  play->angle = play->angle - a;
  if (play->angle >= 2 * M_PI)
    play->angle = play->angle - 2 * M_PI;
  else if (play->angle < 0)
    play->angle = play->angle + 2 * M_PI;
  return (0);
}
