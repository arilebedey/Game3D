#include "../../include/ctx.h"
#include "../../include/dda.h"
#include <math.h>

static void	set_texture(t_ctx *ctx, t_dda *ref_dda, int i);
static void	set_text_pt_x(t_ctx *ctx, t_dda *ref_dda, int i, \
	double perp_wall_dist);

// Initialize the start and end pixels in the col where the wall will be drawn.
void	init_draw_elem(t_ctx *ctx, t_dda *ref_dda, int i)
{
	double	perp_wall_dist;
	int		line_height;

	if (ref_dda->SIZE == 0)
		perp_wall_dist = (ref_dda->SIZE_dist.x - ref_dda->delta_dist.x);
	else
		perp_wall_dist = (ref_dda->SIZE_dist.y - ref_dda->delta_dist.y);
	line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
	ref_dda->col_draw_arr[i].start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (ref_dda->col_draw_arr[i].start < 0)
		ref_dda->col_draw_arr[i].start = 0;
	ref_dda->col_draw_arr[i].end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (ref_dda->col_draw_arr[i].end >= WINDOW_HEIGHT)
		ref_dda->col_draw_arr[i].end = WINDOW_HEIGHT - 1;
	ref_dda->col_draw_arr[i].line_height = line_height;
	set_texture(ctx, ref_dda, i);
	set_text_pt_x(ctx, ref_dda, i, perp_wall_dist);
}

// Set the column of the texture we're gonna draw
static void	set_text_pt_x(t_ctx *ctx, t_dda *ref_dda, int i, \
	double perp_wall_dist)
{
	double	wall_x;
	int		*ref_tex_x;

	ref_tex_x = &ref_dda->col_draw_arr[i].text_pt.x;
	if (ref_dda->SIZE == 0)
		wall_x = ctx->player.position.y + perp_wall_dist * ref_dda->ray.y;
	else
		wall_x = ctx->player.position.x + perp_wall_dist * ref_dda->ray.x;
	wall_x -= floor(wall_x);
	*ref_tex_x = (int)(wall_x * (double)ref_dda->col_draw_arr[i].texture.width);
	if ((ref_dda->SIZE == 0 && ref_dda->ray.x < 0) || \
		(ref_dda->SIZE == 1 && ref_dda->ray.y > 0))
		*ref_tex_x = ref_dda->col_draw_arr[i].texture.width - *ref_tex_x - 1;
}

// Set the texture according to the direction.
static void	set_texture(t_ctx *ctx, t_dda *ref_dda, int i)
{
	if (ref_dda->SIZE == 0)
	{
		if (ref_dda->ray.x > 0)
			ref_dda->col_draw_arr[i].texture = ctx->map.texture_list.west_tex;
		else
			ref_dda->col_draw_arr[i].texture = ctx->map.texture_list.east_tex;
	}
	else
	{
		if (ref_dda->ray.y > 0)
			ref_dda->col_draw_arr[i].texture = ctx->map.texture_list.north_tex;
		else
			ref_dda->col_draw_arr[i].texture = ctx->map.texture_list.south_tex;
	}
}
