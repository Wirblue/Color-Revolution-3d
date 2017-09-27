/*
** boucle.c for w3d in /home/louis.mallez/delivery/CGP/wolf3d/my_src/prepare_ra
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Dec 28 17:36:36 2016 mallez louis
** Last update Wed Sep 27 19:15:54 2017 
*/

#include	"w3d.h"

int		prepare_raycast(t_player *play, t_my_framebuffer *buff,
				t_map *map)
{
  int			line;
  float			temp_angle;
  float			add_angle;
  t_raycaster		ray;

  add_angle = ANGLE / buff->width;
  line = 0;
  while (line <= buff->width)
    {
      temp_angle = atan(((double)line - buff->width / 2)
			/ buff->height) + play->angle;
      ray = my_raycast_wp(play->pos, temp_angle, map);
      if (ray.size > 0)
  	{
  	  ray.size = ray.size * cosf(temp_angle - play->angle);
  	  draw_my_line(buff, &ray, line, map);
  	}
      temp_angle = temp_angle + add_angle;
      line++;
    }
  return (0);
}

int		temp_ray(t_my_framebuffer *buff, t_map *map,
			 t_all_player *plays)
{
  int		i;

  i = 0;
  buff->wd = 0;
  plays->height = buff->height;
  buff->height = buff->height / plays->nbr;
  while (i < plays->nbr)
    {
      sky_floor(buff);
      prepare_raycast(&(plays->play[i]), buff, map);
      cross_hair(buff);
      draw_minimap(buff, map, &(plays->play[i]));
      buff->wd = buff->wd + buff->height;
      i++;
    }
  buff->height = plays->height;
  return (0);
}
