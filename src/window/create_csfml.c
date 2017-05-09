/*
** create_csfml.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Dec 28 17:34:32 2016 mallez louis
** Last update Wed Dec 28 18:04:59 2016 mallez louis
*/

#include "w3d.h"

sfRenderWindow          *create_window(char* name, int width, int height)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return window;
}

sfUint8			*create_pixel_buffer(int width, int height)
{
  int                   i;
  sfUint8*              pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
    return (NULL);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}
