/*
** cursor.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/other
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Tue Jan  3 14:53:27 2017 mallez louis
** Last update Tue Jan  3 15:00:01 2017 mallez louis
*/

#include "w3d.h"

int	cross_hair(t_my_framebuffer *mfb)
{
  int	i;

  i = mfb->width / 2 - CROSS_HAIR / 2;
  while (i != mfb->width / 2 + CROSS_HAIR / 2)
    {
      my_put_pixel(mfb, i, mfb->height / 2, sfRed);
      i++;
    }
  i = mfb->height / 2 - CROSS_HAIR / 2;
  while (i != mfb->height / 2 + CROSS_HAIR / 2)
    {
      my_put_pixel(mfb, mfb->width / 2, i, sfRed);
      i++;
    }
  return (0);
}
