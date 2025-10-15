#include "../../include/ctx.h"
#include "../../include/win.h"
#include "../../mlx_linux/mlx.h"
#include "../../libft/libft.h"
#include "../../include/draw.h"
#include "../../include/map.h"
#include "../../include/dda.h"
#include <stdlib.h>

static void	draw_textured_col(t_ctx *ctx, t_dda dda);

int	render(t_ctx *ctx)
{
	t_dda	dda;

	dda_algo(ctx, &dda);
	draw_textured_col(ctx, dda);
	mlx_put_image_to_window(ctx->win.ptr_mlx, ctx->win.ptr_win, \
		ctx->win.img.ptr_img, 0, 0);
	return (1);
}

// draw all pixels columns
static void	draw_textured_col(t_ctx *ctx, t_dda dda)
{
	int			x;
	int			y;
	double		step;
	double		tex_y;
	t_col_draw	col_draw;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		col_draw = dda.col_draw_arr[x];
		step = 1.0 * col_draw.texture.height / col_draw.line_height;
		tex_y = (col_draw.start - WINDOW_HEIGHT / 2 + \
			col_draw.line_height / 2) * step;
		y = -1;
		while (++y < WINDOW_HEIGHT)
		{
			if (y < col_draw.start)
				img_pix_put(ctx->win, ctx->map.ceiling_color, x, y);
			else if (y >= col_draw.end)
				img_pix_put(ctx->win, ctx->map.floor_color, x, y);
			else
			{
				col_draw.text_pt.y = (int)tex_y;
				tex_y += step;
				img_pix_put(ctx->win, get_texture_pixel(col_draw.texture, \
					col_draw.text_pt.x, col_draw.text_pt.y), x, y);
			}
		}
	}
}
