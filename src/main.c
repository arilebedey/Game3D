#include "../include/ctx.h"
#include "../include/debug.h"
#include "../include/draw.h"
#include "../include/error.h"
#include "../include/texture.h"
#include "../include/win.h"
#include "../include/player.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

static int	loop(t_ctx *ctx);
static int	close_window(t_ctx *ctx);
static void	init_test_values(t_ctx *ctx);
static void	free_ctx(t_ctx *ctx, t_ctx **ref_ctx);

int	main(int ac, char **av)
{
	t_ctx	*ctx;

	(void)av;
	(void)ac;
	// if (ac != 2)
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
	mlx_hook(ctx->win.ptr_win, KeyPress, KeyPressMask, &handle_key_press,
		&ctx->input);
	mlx_hook(ctx->win.ptr_win, KeyRelease, KeyReleaseMask, &handle_key_release,
		&ctx->input);
	mlx_hook(ctx->win.ptr_win, DestroyNotify, 0, &close_window, ctx);
	mlx_loop(ctx->win.ptr_mlx);
	free_ctx(ctx, &ctx);
	return (0);
}

static int	loop(t_ctx *ctx)
{
	debug_input(ctx->input);
	rotate_player(ctx);
	move_player(ctx);
	render(ctx);
	printf("direction: {%f %f}, fov: {%f, %f}, position: {%f %f}\n", ctx->player.direction.x, ctx->player.direction.y, \
		ctx->player.fov.x, ctx->player.fov.y, \
			ctx->player.position.x, ctx->player.position.y);
	if (ctx->input.escape)
		close_window(ctx);
	return (1);
}

// Initialize test values
// A supp quand le parse fonctionnera
static void	init_test_values(t_ctx *ctx)
{
	static char	*hardcoded_tile_list[] = {
		"1111111",
		"10000011111",
		"10101000001",
		"10001101011",
		"11111111111",
		NULL};

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
	ctx->player.direction = ((t_vector2){0, 1});
	rotate_player(ctx);
	ctx->player.position = ((t_vector2){1.5, 1.5});
		// Ne pas oublier d'add 0.5 pour spawn au milieu de la case
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
