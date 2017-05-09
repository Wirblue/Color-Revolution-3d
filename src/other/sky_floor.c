/*
** sky_floor.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/other
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Jan  4 10:05:57 2017 mallez louis
** Last update Tue Jan 10 14:31:59 2017 mallez louis
*/

#include "w3d.h"

int		sky_floor(t_my_framebuffer *mfb)
{
  sfVector2i	sky;
  sfVector2i	floor;
  sfVector2i	size;
  sfColor	color;

  sky.x = 0;
  sky.y = 0;
  floor.x = 0;
  floor.y = mfb->height / 2;
  size.x = mfb->width;
  size.y = mfb->height;
  color = my_sfColor_fromRGB(120, 120, 120);
  color.a = 255;
  draw_little_square(mfb, sky, size, color);
  color = my_sfColor_fromRGB(60, 60, 60);
  color.a = 255;
  draw_little_square(mfb, floor, size, color);
  return (0);
}
