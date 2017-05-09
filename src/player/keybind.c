/*
** keybind.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/player
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Mon Jan  9 14:57:49 2017 mallez louis
** Last update Sun Jan 15 20:25:52 2017 
*/

#include "w3d.h"

int		wait_ev(t_csfml_help *cs_h, sfEvent event)
{
  event.key.code = 51;
  while (event.type != sfEvtKeyPressed)
    sfRenderWindow_waitEvent(cs_h->win, &event);
  return (event.key.code);
}

int		keybind(t_all_player *plays, t_csfml_help *cs_h)
{
  sfEvent	event;
  int		i;

  i = 0;
  while (i < plays->nbr)
    {
      my_printf("\nBind Joueur %d :\n\tMove Forward", i + 1);
      plays->play[i].info.up = wait_ev(cs_h, event);
      my_printf("\n\tMove Back");
      plays->play[i].info.down = wait_ev(cs_h, event);
      my_printf("\n\tTurn Left");
      plays->play[i].info.left = wait_ev(cs_h, event);
      my_printf("\n\tTurn Right");
      plays->play[i].info.right = wait_ev(cs_h, event);
      my_printf("\n\tAction");
      plays->play[i].info.action = wait_ev(cs_h, event);
      my_printf("\n\tPose");
      plays->play[i].info.pose = wait_ev(cs_h, event);
      my_printf("\n");
      i++;
    }
  return (0);
}
