#include "../include/cleanup.h"
#include "../include/ctx.h"
#include "../include/debug.h"
#include "../include/draw.h"
#include "../include/error.h"
#include "../include/parse.h"
#include "../include/player.h"
#include "../include/win.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

static int	loop(t_ctx *ctx);
static int	close_window(t_ctx *ctx);

int	main(int ac, char **av)
{
	t_ctx	*ctx;

	(void)av;
	(void)ac;
	if (ac != 2)
		return (perr("error: args"), 1);
	ctx = ft_calloc(1, sizeof(t_ctx));
	if (!ctx)
		return (perr("error: ctx malloc"), 1);
	if (!parse(ctx, av[1]))
		return (free(ctx), 1);
	if (!init_window(&ctx->win) || !init_image(&ctx->win))
		return (1);
	ctx->mouse_active = 1;
	mlx_mouse_move(ctx->win.ptr_mlx, ctx->win.ptr_win, WINDOW_WIDTH / 2,
		WINDOW_HEIGHT / 2);
	init_input(&ctx->input);
	if (!load_textures(ctx))
		return (free_ctx(ctx, &ctx), 1);
	mlx_loop_hook(ctx->win.ptr_mlx, &loop, ctx);
	mlx_hook(ctx->win.ptr_win, KeyPress, KeyPressMask, handle_key_press, ctx);
	mlx_hook(ctx->win.ptr_win, KeyRelease, KeyReleaseMask, handle_key_release,
		ctx);
	mlx_hook(ctx->win.ptr_win, DestroyNotify, 0, &close_window, ctx);
	mlx_loop(ctx->win.ptr_mlx);
	free_ctx(ctx, &ctx);
	return (0);
}

static int	loop(t_ctx *ctx)
{
	handle_mouse(ctx);
	rotate_player(ctx);
	move_player(ctx);
	render(ctx);
	/* printf("direction: {%f %f}, fov: {%f, %f}, position: {%f %f}\n", */
	/* 	ctx->player.direction.x, ctx->player.direction.y, ctx->player.fov.x, */
	/* 	ctx->player.fov.y, ctx->player.position.x, ctx->player.position.y); */
	if (ctx->input.escape)
		close_window(ctx);
	return (1);
}

static int	close_window(t_ctx *ctx)
{
	mlx_loop_end(ctx->win.ptr_mlx);
	return (0);
}
