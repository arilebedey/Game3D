#ifndef MAP_H
# define MAP_H

# include "win.h"
# include "rgb.h"
# include "win.h"
# include "texture.h"

typedef struct s_texture_list
{
	t_texture	north_tex;
	t_texture	south_tex;
	t_texture	west_tex;
	t_texture	east_tex;
}		t_texture_list;

typedef struct s_map
{
	char			**tile_list;
	int				width;
	int				height;
	int				floor_color;
	int				ceiling_color;
	t_texture_list	texture_list;
}		t_map;

#endif
