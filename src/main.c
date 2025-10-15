#include "../include/win.h"
#include "../include/texture.h"
#include "../include/ctx.h"
#include "../include/error.h"
#include "../mlx_linux/mlx.h"
#include "../include/draw.h"
#include <stdlib.h>
#include <X11/X.h>
#include "../libft/libft.h"
#include "../include/texture.h"
#include "../include/debug.h"

static int	loop(t_ctx *ctx);
static int	close_window(t_ctx *ctx);
static void	init_test_values(t_ctx *ctx);
static void	free_ctx(t_ctx *ctx, t_ctx **ref_ctx);

int	main(int ac, char **av)
{
	t_ctx	*ctx;

	(void)av;
	(void)ac;
	//if (ac != 2)
	//	return (perr("error: args"), 1);
	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		return (perr("error: ctx malloc"), 1);
	//🤓TODO: parse here (aristark lebedev)🤓
	if (!init_window(&ctx->win) || !init_image(&ctx->win))
		return (1);
	init_input(&ctx->input);
	init_test_values(ctx); // TODO: a supp quand le parse fonctionnera
	if (!load_textures(ctx))
		return (free_ctx(ctx, &ctx), 1);
	mlx_loop_hook(ctx->win.ptr_mlx, &loop, ctx);
	mlx_hook(ctx->win.ptr_win, KeyPress, KeyPressMask, &handle_key_press, \
		&ctx->input);
	mlx_hook(ctx->win.ptr_win, KeyRelease, KeyReleaseMask, \
		&handle_key_release, &ctx->input);
	mlx_hook(ctx->win.ptr_win, DestroyNotify, 0, &close_window, ctx);
	mlx_loop(ctx->win.ptr_mlx);
	free_ctx(ctx, &ctx);
	return (0);
}

// Main loop.
#include <stdio.h>
static int	loop(t_ctx *ctx)
{
	debug_input(ctx->input);
	//🤓 TODO: calculates player move and rotation according to input (aristark lebedev)🤓
	borders_collision(ctx);
	render(ctx);
	if (ctx->input.escape)
		close_window(ctx);
	return (1);
}

// Initialize test values
// A supp quand le parse fonctionnera
static void	init_test_values(t_ctx *ctx)
{
	static char	*hardcoded_tile_list[] = {
		"111111",
		"100001",
		"100001",
		"100001",
		"111111",
		NULL
	};
	ctx->map.tile_list = hardcoded_tile_list;
	ctx->map.ceiling_color = encode_rgb((t_rgb){255, 0, 0});
	ctx->map.floor_color = encode_rgb((t_rgb){230, 230, 170});
	ctx->map.texture_list.north_tex.width = 256;
	ctx->map.texture_list.north_tex.height = 256;
	ctx->map.texture_list.north_tex.path = "./texture/neco_gun.xpm";
	ctx->map.texture_list.south_tex.width = 256;
	ctx->map.texture_list.south_tex.height = 256;
	ctx->map.texture_list.south_tex.path = "./texture/neco_wine.xpm";
	ctx->map.texture_list.west_tex.width = 256;
	ctx->map.texture_list.west_tex.height = 256;
	ctx->map.texture_list.west_tex.path = "./texture/neco_cute.xpm";
	ctx->map.texture_list.east_tex.width = 256;
	ctx->map.texture_list.east_tex.height = 256;
	ctx->map.texture_list.east_tex.path = "./texture/neco_boom.xpm";
	ctx->map.height = 5;
	ctx->map.width = 6;
	ctx->player.direction = ((t_vector2){0, 1});
	ctx->player.fov = ((t_vector2){-0.66, 0});
	ctx->player.position = ((t_vector2){2.5, 1.5});
}

// Close the window.
static int	close_window(t_ctx *ctx)
{
	mlx_loop_end(ctx->win.ptr_mlx);
	return (0);
}

// Free ctx and all its fields.
static void	free_ctx(t_ctx *ctx, t_ctx **ref_ctx)
{
	destroy_textures_images(ctx, 3);
	mlx_destroy_image(ctx->win.ptr_mlx, ctx->win.img.ptr_img);
	mlx_destroy_window(ctx->win.ptr_mlx, ctx->win.ptr_win);
	mlx_destroy_display(ctx->win.ptr_mlx);
	free(ctx->win.ptr_mlx);
	free(*ref_ctx);
}
