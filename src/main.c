/*
** main.c for eo in /home/louis.mallez/delivery/CGP/wolf3d
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Dec 28 17:39:23 2016 mallez louis
** Last update Tue May  9 10:16:39 2017 
*/

#include "w3d.h"

void			size_window(t_my_framebuffer *mfb)
{
  mfb->width = WIDTH;
  mfb->height = HEIGHT;
}

int			main(int ac __attribute__((unused)), char **av, char **ae)
{
  t_my_framebuffer	mfb;
  t_map			map;

  if (check_env(ae) == -1)
    return(failed_we("CR3D:\tInvalide Env\n", 1));
  if (main_read(av[1], &map) == -1)
    return (1);
  if (texture_reader(&map) == -1)
    return (1);
  size_window(&mfb);
  if (prepare_window(&mfb, &map) == -1)
    return (1);
  return (0);
}
