/*
** draw_my_line.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/line
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Tue Jan  3 09:46:14 2017 mallez louis
** Last update Wed Sep 27 19:13:16 2017 
*/

#include "w3d.h"

int		draw_my_line(t_my_framebuffer *buff, t_raycaster *ray,
			     int line, t_map *map)
{
  int		start;
  float		size;
  int		i;
  sfColor	t;
  int		haut;

  if (ray->size < 0 || ray->size >= R_DIST - 1)
    return (0);
  i = 0;
  size = buff->height * 2 / (ray->size * TAILLE_MUR);
  start = buff->height / 2 - size / 2;
  t = map->text.color[ray->wall.color];
  while (i <= size)
    {
      haut = (int)(i * 10 / size) * 11;
      t.a = 25 * map->text.text_wall[ray->wall.type - 1][haut];
      if (ray->face == 0)
      	t.a = 3 * t.a / 4;
      my_put_pixel(buff, line, start + i, t);
      i++;
    }
  return (0);
}
