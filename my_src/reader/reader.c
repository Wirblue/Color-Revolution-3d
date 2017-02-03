/*
** reader.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/reader
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Tue Jan  3 11:15:26 2017 mallez louis
** Last update Fri Feb  3 20:07:59 2017 
*/

#include "w3d.h"

int		prepare_buff(char *name)
{
  int		i;
  int		j;
  int		fd;
  char		*random;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (failed_we("CR3D:\tfile not found\n", -1));
  i = 0;
  if ((random = malloc((SIZE_READ + 1) * sizeof(char))) == NULL)
    return (failed_we("CR3D:\tmalloc failed\n", -1));
  while ((j = read(fd, random, SIZE_READ)) != 0)
    i = i + j;
  close(fd);
  free(random);
  return (i);
}

char		*my_read(char *name)
{
  int		size;
  int		fd;
  char		*buff;

  if ((size = prepare_buff(name)) == -1)
    return (NULL);
  if ((fd = open(name, O_RDONLY)) == -1)
    return (failed_wc("CR2D:\tfile not found", NULL));
  if ((buff = malloc((size + 1) * sizeof(char))) == NULL)
    return (failed_wc("CR3D:\tmalloc failed\n", NULL));
  if ((read(fd, buff, size)) == -1)
    return (failed_wc("CR3D:\tread error", NULL));
  buff[size] = '\0';
  return (buff);
}

int		main_read(char *name, t_map *map)
{
  char		*buff;

  if ((buff = my_read(name)) == NULL)
    return (-1);
  if (buff[my_strlen(buff) - 1] != '\n')
    return (failed_we("CR3D:\tInvalid map", -1));
  if (verif_buff(buff) == -1)
    return (failed_we("CR3D:\tthis map can't be read\n", -1));
  if (my_tab_maker(buff, map) == -1)
    return (-1);
  return (0);
}
