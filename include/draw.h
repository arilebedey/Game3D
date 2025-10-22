/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:11:56 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 13:11:56 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "ctx.h"
# include "win.h"

typedef struct s_draw
{
	t_point	pt;
	double	step;
	double	tex_y;
}			t_draw;

// render.c

// Main render.
int			render(t_ctx *ctx);

// pixel.c

// Draw a single pixel.
void		img_pix_put(t_win win, int color, int x, int y);

// Draw ceiling and floor.
void		draw_background(t_ctx *ctx);

#endif
