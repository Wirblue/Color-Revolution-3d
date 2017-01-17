/*
** utilitary_fct.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Dec 28 17:44:18 2016 mallez louis
** Last update Sun Jan 15 19:50:20 2017 
*/

#include "w3d.h"

int		failed_we(char *error, int ret)
{
  int		i;

  i = 0;
  while (error[i] != '\0')
    i++;
  write(1, error, i);
  return (ret);
}

char		*failed_wc(char *error, char *ret)
{
  int		i;

  i = 0;
  while (error[i] != '\0')
    i++;
  write(1, error, i);
  return (ret);
}

sfColor		my_sfColor_fromRGB(int b, int g, int r)
{
  sfColor	color;

  color.b = b;
  color.g = g;
  color.r = r;
  return (color);
}
