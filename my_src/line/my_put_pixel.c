/*
** my_put_pixel.c for wireframe in /home/louis.mallez/delivery/CGP/wireframe
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Thu Nov 17 18:06:32 2016 mallez louis
** Last update Sun Jan 15 20:33:40 2017 
*/

#include "w3d.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x, int y, sfColor color)
{
  if ((x > 0 && x < framebuffer->width)
      && (y > 0 && y < framebuffer->height))
    {
      framebuffer->pixels[(framebuffer->width *
			   (y + framebuffer->wd)  + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width *
			   (y + framebuffer->wd) + x) * 4 + 1] = color.b;
      framebuffer->pixels[(framebuffer->width *
			   (y + framebuffer->wd) + x) * 4 + 2] = color.g;
      framebuffer->pixels[(framebuffer->width *
			   (y + framebuffer->wd) + x) * 4 + 3]= color.a;
    }
}
