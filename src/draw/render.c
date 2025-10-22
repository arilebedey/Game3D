/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:39:12 by agense            #+#    #+#             */
/*   Updated: 2025/10/22 12:40:09 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ctx.h"
#include "../../include/win.h"
#include "../../include/point.h"
#include "../../mlx_linux/mlx.h"
#include "../../libft/libft.h"
#include "../../include/draw.h"
#include "../../include/map.h"
#include "../../include/dda.h"
#include <stdlib.h>

// draw function
static void	draw(t_ctx *ctx, t_dda dda);
// draw individual column
static void	draw_col(t_ctx *ctx, t_col_draw col_draw, t_draw *ref_draw);

int	render(t_ctx *ctx)
{
	t_dda	dda;

	dda_algo(ctx, &dda);
	draw(ctx, dda);
	mlx_put_image_to_window(ctx->win.ptr_mlx, ctx->win.ptr_win, \
		ctx->win.img.ptr_img, 0, 0);
	return (1);
}

// draw function
static void	draw(t_ctx *ctx, t_dda dda)
{
	t_draw		draw;
	t_col_draw	col_draw;

	draw.pt.x = -1;
	while (++draw.pt.x < WINDOW_WIDTH)
	{
		col_draw = dda.col_draw_arr[draw.pt.x];
		draw.step = 1.0 * col_draw.texture.height / col_draw.line_height;
		draw.tex_y = (col_draw.start - WINDOW_HEIGHT / 2 + \
			col_draw.line_height / 2) * draw.step;
		draw.pt.y = -1;
		while (++draw.pt.y < WINDOW_HEIGHT)
			draw_col(ctx, col_draw, &draw);
	}
}

static void	draw_col(t_ctx *ctx, t_col_draw col_draw, t_draw *ref_draw)
{
	if (ref_draw->pt.y < col_draw.start)
		img_pix_put(ctx->win, ctx->map.ceiling_color, ref_draw->pt.x, \
			ref_draw->pt.y);
	else if (ref_draw->pt.y >= col_draw.end)
		img_pix_put(ctx->win, ctx->map.floor_color, ref_draw->pt.x, \
			ref_draw->pt.y);
	else
	{
		col_draw.text_pt.y = (int)ref_draw->tex_y;
		ref_draw->tex_y += ref_draw->step;
		img_pix_put(ctx->win, get_texture_pixel(col_draw.texture, \
			col_draw.text_pt.x, col_draw.text_pt.y), ref_draw->pt.x, \
				ref_draw->pt.y);
	}
}
