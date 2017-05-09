/*
** env.c for ev in /home/louis_mallez/delivery/MUL/wolf3d/my_src
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Fri Jan 20 11:06:12 2017 
** Last update Fri Jan 20 11:07:35 2017 
*/

#include "w3d.h"

int     check_env(char **ae)
{
  int   i;

  i = 0;
  while (ae[i] != NULL)
    {
      if (my_strncmp(ae[i], "DISPLAY=:", 9) == 0)
        return (0);
      i++;
    }
  return (-1);
}
