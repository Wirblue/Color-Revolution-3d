/*
** you_win.c for you_win in /home/louis_mallez/delivery/MUL/wolf3d/my_src/victory
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Sat Jan 14 19:49:34 2017 
** Last update Sun Jan 15 21:00:02 2017 
*/

#include "w3d.h"

int		count_total(t_map *map)
{
  sfVector2i	test;
  int		i;

  i = 0;
  test.x = 0;
  test.y = 0;
   while (test.y < map->mapSize.y)
    {
      test.x = 0;
      while (test.x < map->mapSize.x)
        {
	  if (map->map[test.y][test.x].type != 0
	      && bordure(map, test) > 0)
	    i++;
          test.x++;
        }
      test.y++;
    }
   return (i);
}

int		count_color(t_map *map, int c)
{
  sfVector2i	test;
  int		i;

  i = 0;
  test.x = 0;
  test.y = 0;
  while (test.y < map->mapSize.y)
    {
      test.x = 0;
      while (test.x < map->mapSize.x)
        {
	  if (map->map[test.y][test.x].type != 0
	      && map->map[test.y][test.x].color == c
	      && bordure(map, test) > 0)
	    i++;
          test.x++;
        }
      test.y++;
    }
  return (i);
}

int		you_win(t_my_framebuffer *mfb, t_map *map)
{
  int		total;
  int		i;
  sfVector2i	size;
  sfVector2i	pos;
  sfColor	t;

  pos.x = 0;
  pos.y = 0;
  size.y = mfb->height;
  total = count_total(map);
  i = 1;
  mfb->wd = 0;
  while (i < 10)
    {
      t = map->text.color[i];
      t.a = 255;
      size.x = mfb->width * count_color(map, i) / total;
      draw_little_square(mfb, pos, size, t);
      pos.x = pos.x + size.x;
      i++;
    }
  return (0);
}
