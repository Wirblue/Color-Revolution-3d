/*
** utils.c for utils in /home/louis_mallez/delivery/dante/breadth
** 
** Made by 
** Login   <louis.mallez@epitech.eu>
** 
** Started on  Fri Apr 28 14:22:24 2017 
** Last update Tue May  9 10:07:14 2017 
*/

#include "gen.h"

void	exit_we(int nb, char *mes)
{
  write(2, mes, strlen(mes));
  exit(nb);
}
