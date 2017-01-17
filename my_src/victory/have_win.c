/*
** have_win.c for w3d in /home/louis_mallez/delivery/MUL/wolf3d/my_src/victory
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Sat Jan 14 18:52:57 2017 
** Last update Sun Jan 15 20:51:23 2017 
*/

#include "w3d.h"

int		bordure(t_map *map, sfVector2i test)
{
  int		i;

  i = 0;
  if (test.x != 0 && map->map[test.y][test.x - 1].type == 0)
    i++;
  if (test.y != 0 && map->map[test.y - 1][test.x].type == 0)
    i++;
  if (test.x < map->mapSize.x - 1 && map->map[test.y][test.x + 1].type == 0)
    i++;
  if (test.y < map->mapSize.y - 1 && map->map[test.y + 1][test.x].type == 0)
    i++;
  return (i);
}

int		have_win(t_my_framebuffer *mfb, t_map *map)
{
  sfVector2i	test;

  test.x = 0;
  test.y = 0;
  while (test.y < map->mapSize.y)
    {
      test.x = 0;
      while (test.x < map->mapSize.x)
	{
	  if ((map->map[test.y][test.x].type > 0
	      && map->map[test.y][test.x].color == 0)
	     && bordure(map, test) > 0)
	    return (0);
	  test.x++;
	}
      test.y++;
    }
  you_win(mfb, map);
  return (2);
}
