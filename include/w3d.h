/*
** w3d.h for w3d in /home/louis.mallez/delivery/CGP/wolf3d/include
**
** Made by mallez louis
** Login   <louis.mallez@epitech.net>
**
** Started on  Wed Dec 28 17:36:36 2016 mallez louis
** Last update Tue May  9 10:14:24 2017 
*/

#ifndef W3D_H_
#define W3D_H_

#include "my_printf.h"
#include "my.h"
#include "math.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define WIDTH 1200
#define HEIGHT 1000

#define OUT (cs_h->event.key.code != sfKeyEscape && cs_h != sfEvtClosed)

#define ANGLE (5 * M_PI) / 9
#define PRECISION 0.01
#define SPEED 0.1
#define ROTATE 0.05

#define SIZE_READ 100
#define SIZE_TEXTURE 110

#define MAP_SX map->mapSize.x
#define MAP_SY map->mapSize.y
#define CROSS_HAIR 30
#define OMBRAGE 0.5
#define R_DIST 30
#define TAILLE_MUR 2

#define MINIM_X 850
#define MINIM_Y 50
#define MINIM_SIZE 100
#define MINIM_SIZEX MINIM_SIZE / map->mapSize.x
#define MINIM_SIZEY MINIM_SIZE / map->mapSize.y

#define IRAYX ((int)(ray->pos.x))
#define IRAYY ((int)(ray->pos.y))

#define FACE_X ((ray->pos.x - IRAYX) / (ray->pos.y - IRAYY) - 1)
#define FACE_Y (-(ray->pos.x - IRAYX - 1) / (ray->pos.y - IRAYY) - 1)

/* #define SIX framebuffer->s.x */
/* #define SIY framebuffer->s.y */

typedef struct		s_csfml_help
{
  sfRenderWindow	*win;
  sfTexture		*tex;
  sfSprite		*spr;
  sfEvent		event;
}			t_csfml_help;

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			wd;
  int			height;
}			t_my_framebuffer;

typedef struct		s_info_play
{
  int			up;
  int			down;
  int			left;
  int			right;
  int			action;
  int			pose;
  sfColor		c;
}			t_info_play;

typedef struct		s_player
{
  sfVector2f		pos;
  float			angle;
  t_info_play		info;
  int			bloc;
}			t_player;

typedef struct		s_all_player
{
  t_player		*play;
  int			nbr;
  int			height;
}			t_all_player;

typedef struct          s_color_tab
{
  int                   num;
  int                   b;
  int                   r;
  int                   g;
}                       t_color_tab;

typedef struct		s_bloc
{
  char			type;
  int			color;
}			t_bloc;

typedef struct		s_raycaster
{
  sfVector2f		pos;
  float			size;
  t_bloc		wall;
  int			larg;
  int			face;
}			t_raycaster;

typedef struct		s_texture
{
  sfColor		color[9];
  char			*text_wall[9];
}			t_texture;

typedef struct		s_map
{
  sfVector2i		mapSize;
  t_bloc		**map;
  t_texture		text;
}			t_map;

int			failed_we(char *error, int ret);
char			*failed_wc(char *error, char *ret);
sfRenderWindow		*create_window(char* name, int width, int height);
sfUint8			*create_pixel_buffer(int width, int height);
int                     prepare_window(t_my_framebuffer *mfb, t_map *map);
int			my_tab_maker(char *buff, t_map *map);
int			main_read(char *name, t_map *map);
t_raycaster		my_raycast(sfVector2f pos, float direction,
				   t_bloc **map, sfVector2i mapSize);
t_raycaster		my_raycast_wp(sfVector2f pos, float direction,
				   t_map *map, t_all_player *plays);
int			move_turn(t_player *play, float a);
sfVector2f		mmove_forward(sfVector2f pos, float direction,
				      float distance, t_map *map);
void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color);
int			draw_my_line(t_my_framebuffer *buff, t_raycaster *ray,
				     int line, t_map *map);
int			open_the_door(t_player *play, t_map *map);

int			draw_little_square(t_my_framebuffer *mfb,
					   sfVector2i pos,
					   sfVector2i size,
					   sfColor color);
int			draw_minimap(t_my_framebuffer *mfb, t_map *map,
			     t_player *play);
int			sky_floor(t_my_framebuffer *mfb);
int			cross_hair(t_my_framebuffer *mfb);
void			all_black(t_my_framebuffer *mfb);
int			what_event(t_csfml_help *, t_all_player *plays,
				   t_my_framebuffer *mfb,
				   t_map *map);
int			temp_ray(t_my_framebuffer *buff, t_map *map,
			 t_all_player *plays);
int			init_player(t_map *map, t_all_player *plays);
sfColor			my_sfColor_fromRGB(int, int, int);
int			keybind(t_all_player *, t_csfml_help *);
int			pose_bloc(t_player *, t_map *);
int			texture_reader(t_map *);
int			color_reader(t_map *);
int			have_win(t_my_framebuffer *, t_map *);
int			you_win(t_my_framebuffer *, t_map *);
int			bordure(t_map *, sfVector2i);
int			verif_buff(char *);
int			check_env(char **);
int			map_gen(t_map *);

#endif /* W3D_H_ */
