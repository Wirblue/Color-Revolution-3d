/*
** minimap.c for minimap.c in /home/louis.mallez/delivery/CGP/wolf3d/my_src/oth
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Jan  4 08:35:27 2017 mallez louis
** Last update Fri Jan 13 17:41:38 2017 
*/

#include "w3d.h"

int	draw_little_square(t_my_framebuffer *mfb, sfVector2i pos,
			   sfVector2i size, sfColor color)
{
  int	w;
  int	h;

  w = 0;
  h = 0;
  h = 0;
  while (h != size.y)
    {
      w = 0;
      while (w != size.x)
  	{
	  my_put_pixel(mfb, pos.x + w, pos.y + h, color);
	  w++;
  	}
      h++;
    }
  return (0);
}

int		place_player(t_my_framebuffer *mfb, t_player *play, t_map *map)
{
  sfVector2i	cpm;
  sfVector2i	size;

  cpm.x = play->pos.x * (MINIM_SIZEX) + MINIM_X;
  cpm.y = play->pos.y * (MINIM_SIZEY) + MINIM_Y;
  size.x = MINIM_SIZE / 25;
  size.y = MINIM_SIZE / 25;
  draw_little_square(mfb, cpm, size, sfRed);
  return (0);
}

int		draw_minimap(t_my_framebuffer *mfb, t_map *map, t_player *play)
{
  int		x;
  int		y;
  sfVector2i	posmini;
  sfVector2i	size;

  size.x = MINIM_SIZEX;
  size.y = MINIM_SIZEY;
  y = 0;
  posmini.y = MINIM_Y;
  while (y != map->mapSize.y)
    {
      x = 0;
      posmini.x = MINIM_X;
      while (x != map->mapSize.x)
	{
	  if (map->map[y][x].type == 0)
	    draw_little_square(mfb, posmini, size, sfMagenta);
	  posmini.x = posmini.x + MINIM_SIZEX;
	  x++;
	}
      posmini.y = posmini.y + MINIM_SIZEY;
      y++;
    }
  place_player(mfb, play, map);
  return (0);
}
