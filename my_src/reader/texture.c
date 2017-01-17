/*
** texture.c for texture in /home/louis_mallez/delivery/MUL/wolf3d/my_src/reade
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Fri Jan 13 15:53:08 2017 
** Last update Sun Jan 15 20:52:49 2017 
*/

#include "w3d.h"

char	*prepare_pn(char *path)
{
  char	*calc;
  int	fd;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (failed_wc("wolf3d:\ttexture not fount\n", NULL));
  if ((calc = malloc((SIZE_TEXTURE + 1) * sizeof(char))) == NULL)
    return (failed_wc("wolf3d:\terror malloc\n", NULL));
  calc[SIZE_TEXTURE + 1] = '\0';
  if (read(fd, calc, SIZE_TEXTURE) == -1)
    return (failed_wc("wolf3d:\terror read\n", NULL));
  return (calc);
}

char	*my_strdup(char *c, int size)
{
  char	*d;
  int	i;

  i = 0;
  if ((d = malloc((size + 1) * sizeof(char))) == NULL)
    return (failed_wc("wolf3d:\terror malloc\n", NULL));
  d[size] = '\0';
  while (c[i] != '\0')
    {
      d[i] = c[i];
      i++;
    }
  return (d);
}

int	texture_reader(t_map *map)
{
  int	i;
  char	*path;

  if ((path = my_strdup("texture/wall0", 13)) == NULL)
    return (-1);
  i = 0;
  while (i < 9)
    {
      path[12] = i + 49;
      if ((map->text.text_wall[i] =
	   malloc((SIZE_READ + 1) * sizeof(char))) == NULL)
	return (failed_we("wolf3d:\terror malloc\n", -1));
      map->text.text_wall[SIZE_READ] = '\0';
      if ((map->text.text_wall[i] = prepare_pn(path)) == NULL)
      	return (-1);
      i++;
    }
  if (color_reader(map) == -1)
    return (-1);
  return (0);
}
