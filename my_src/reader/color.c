/*
** color.c for w3d in /home/louis_mallez/delivery/MUL/wolf3d/my_src/reader
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Sat Jan 14 20:54:23 2017 
** Last update Sat Jan 14 21:59:30 2017 
*/

#include "w3d.h"

int	get_nombre(char *nbr)
{
  int	i;

  i = nbr[0] - 48;
  i = i * 10 + nbr[1] - 48;
  i = i * 10 + nbr[2] - 48;
  return (i);
}

int	color_reader(t_map *map)
{
  int	i;
  int	fd;
  char	*temp;

  fd = open("texture/color", O_RDONLY);
  temp = malloc(4 * sizeof(char));
  temp[3] = '\0';
  i = 0;
  while (i < 9)
    {
      if (read(fd, temp, 3) != 3)
  	return (-1);
      map->text.color[i].r = get_nombre(temp);
      if (read(fd, temp, 3) != 3)
	return (-1);
      map->text.color[i].g = get_nombre(temp);
      if (read(fd, temp, 3) != 3)
	return (-1);
      map->text.color[i].b = get_nombre(temp);
      read(fd, temp, 1);
      i++;
    }
  return (0);
}
