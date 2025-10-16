#ifndef DRAW_H
# define DRAW_H

# include "ctx.h"
# include "win.h"

// render.c

// Main render.
int		render(t_ctx *ctx);

// pixel.c

// Draw a single pixel.
void	img_pix_put(t_win win, int color, int x, int y);

// Draw ceiling and floor.
void	draw_background(t_ctx *ctx);

#endif
