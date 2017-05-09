/*
** verif_buff.c for w3d in /home/louis_mallez/delivery/MUL/wolf3d
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Sun Jan 15 20:00:21 2017 
** Last update Sun Jan 15 20:51:40 2017 
*/

#include "w3d.h"

int	verif_buff(char *buff)
{
  int	i;
  int	cp_i;
  int	j;

  j = 0;
  i = 0;
  while (buff[i] != '\n')
    i++;
  cp_i = i;
  i = 0;
  while (buff[i] != '\0')
    {
      if ((buff[i] > '9' || buff[i] < '0')
	  && buff[i] != '\n' && buff[i] != 'p')
	return (-1);
      if (buff[i] == '\n')
	{
	  if (j != cp_i)
	    return (-1);
	  j = -1;
	}
      i++;
      j++;
    }
  return (0);
}
