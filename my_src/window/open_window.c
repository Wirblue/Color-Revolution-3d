/*
** my_true_square.c for hhh in /home/louis.mallez/delivery/CGP/Bootstrap
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Nov  9 16:13:20 2016 mallez louis
** Last update Sun Jan 15 20:56:57 2017 
*/

#include "w3d.h"

int			update_window(t_csfml_help *cs_h)
{
  sfRenderWindow_clear(cs_h->win, sfBlack);
  sfRenderWindow_drawSprite(cs_h->win, cs_h->spr, NULL);
  sfRenderWindow_display(cs_h->win);
  return (0);
}

int			open_window(t_my_framebuffer *mfb,
				    t_csfml_help *cs_h,
				    t_map *map, t_all_player *plays)
{
  int			i;

  i = 1;
  temp_ray(mfb, map, plays);
  sfTexture_updateFromPixels(cs_h->tex,
			     mfb->pixels, mfb->width, mfb->height, 0, 0);
  while (sfRenderWindow_isOpen(cs_h->win) && OUT)
    {
      if (i == 1)
	i = keybind(plays, cs_h);
      sfRenderWindow_pollEvent(cs_h->win, &(cs_h->event));
      if (cs_h->event.type == sfEvtKeyPressed && i != 2)
	{
	  what_event(cs_h, plays, mfb, map);
	  i = have_win(mfb, map);
	  sfTexture_updateFromPixels(cs_h->tex, mfb->pixels,
				     mfb->width, mfb->height, 0, 0);
	}
      update_window(cs_h);
    }
  return (0);
}

int			prepare_window(t_my_framebuffer *mfb, t_map *map)
{
  t_csfml_help		cs_h;
  t_all_player		plays;

  cs_h.win = create_window("MALLEZ WOLF3D", mfb->width, mfb->height);
  if (cs_h.win == NULL)
    return (-1);
  cs_h.spr = sfSprite_create();
  cs_h.tex = sfTexture_create(mfb->width, mfb->height);
  mfb->pixels = create_pixel_buffer(mfb->width, mfb->height);
  if (mfb->pixels == NULL)
    return (-1);
  sfSprite_setTexture(cs_h.spr, cs_h.tex, sfTrue);
  if (init_player(map, &plays) == -1)
    return (-1);
  open_window(mfb, &cs_h, map, &plays);
  sfRenderWindow_destroy(cs_h.win);
  return (0);
}
