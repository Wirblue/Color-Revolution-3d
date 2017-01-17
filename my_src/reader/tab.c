/*
** tab.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/reader
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Mon Jan  2 12:36:41 2017 mallez louis
** Last update Sun Jan 15 19:57:46 2017 
*/

#include "w3d.h"

int	init_tab(t_map *map)
{
  int	i;

  i = 0;
  if ((map->map = malloc(MAP_SY * sizeof(t_bloc[MAP_SX]))) == NULL)
    return (failed_we("wolf2d:\tmalloc error\n", -1));
  while (i != MAP_SY)
    {
      if ((map->map[i] = malloc(MAP_SX * sizeof(t_bloc))) == NULL)
	return (failed_we("wolf2d:\tmalloc error\n", -1));
      i++;
    }
  return (0);
}

int	make_tab(char *buff, t_map *map)
{
  int	x;
  int	y;
  int	i;

  i = 0;
  y = 0;
  if (init_tab(map) == -1)
    return (-1);
  while (buff[i] != '\0')
    {
      x = 0;
      while (buff[i] != '\n' && buff[i] != '\0')
	{
	  map->map[y][x].type = buff[i] - 48;
	  map->map[y][x].color = 0;
	  x++;
	  i++;
	}
      if (buff[i] != '\0')
	i++;
      y++;
    }
  return (0);
}

int	my_tab_maker(char *buff, t_map *map)
{
  int	i;

  i = 0;
  MAP_SX = 0;
  MAP_SY = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
    {
      MAP_SX++;
      i++;
    }
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	MAP_SY++;
      if (buff[i] != '\0')
	i++;
    }
  if (make_tab(buff, map) == -1)
    return (-1);
  return (0);
}
