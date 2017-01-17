/*
** event.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/window
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Tue Jan  3 13:53:19 2017 mallez louis
** Last update Sun Jan 15 20:50:04 2017 
*/

#include "w3d.h"

int	what_event(t_csfml_help *cs, t_all_player *plays,
		   t_my_framebuffer *mfb,
		   t_map *map)
{
  int	i;

  i = 0;
  all_black(mfb);

  while (i < plays->nbr)
    {
      if (sfKeyboard_isKeyPressed(plays->play[i].info.up))
	plays->play[i].pos = mmove_forward(plays->play[i].pos,
					   plays->play[i].angle, SPEED, map);
      if (sfKeyboard_isKeyPressed(plays->play[i].info.down))
	plays->play[i].pos = mmove_forward(plays->play[i].pos,
					   plays->play[i].angle, -SPEED, map);
      if (sfKeyboard_isKeyPressed(plays->play[i].info.right))
	move_turn(&(plays->play[i]), -ROTATE);
      if (sfKeyboard_isKeyPressed(plays->play[i].info.left))
	move_turn(&(plays->play[i]), ROTATE);
      if (sfKeyboard_isKeyPressed(plays->play[i].info.action))
      	open_the_door(&(plays->play[i]), map);
      if (sfKeyboard_isKeyPressed(plays->play[i].info.pose))
      	pose_bloc(&(plays->play[i]), map);
      i++;
    }
  if (cs->event.key.code == sfKeyF7)
    keybind(plays, cs);
  temp_ray(mfb, map, plays);
  return (0);
}
