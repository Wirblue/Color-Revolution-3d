/*
** all_black.c for aled in /home/louis.mallez/delivery/CGP/wireframe
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Nov 16 13:57:06 2016 mallez louis
** Last update Tue Jan  3 14:15:40 2017 mallez louis
*/

#include "w3d.h"

void	all_black(t_my_framebuffer *mfb)
{
  int	i;

  i = mfb->height * mfb->width * 4;
  while (i > 0)
    {
      i--;
      mfb->pixels[i] = 0;
    }
}
