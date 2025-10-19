#ifndef DDA_H
# define DDA_H

# include "texture.h"

typedef struct s_vector2	t_vector2;
typedef struct s_point		t_point;

typedef struct s_col_draw
{
	int			start;
	int			end;
	int			line_height;
	t_point		text_pt;
	t_texture	texture;

}		t_col_draw;

typedef struct s_dda
{
	t_vector2	ray;
	t_point		tile;
	t_point		step;
	t_vector2	delta_dist;
	t_vector2	SIZE_dist;
	t_col_draw	col_draw_arr[WINDOW_WIDTH];
	int			SIZE;

}		t_dda;

// Make all dda calculations.
void	dda_algo(t_ctx *ctx, t_dda *ref_dda);

// Init a draw elem at index i using dda fields.
void	init_draw_elem(t_ctx *ctx, t_dda *ref_dda, int i);

#endif
