#include "../include/ctx.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>

void	free_textures(t_ctx *ctx)
{
	free(ctx->map.texture_list.north_tex.path);
	free(ctx->map.texture_list.south_tex.path);
	free(ctx->map.texture_list.west_tex.path);
	free(ctx->map.texture_list.east_tex.path);
	ctx->map.texture_list.north_tex.path = NULL;
	ctx->map.texture_list.south_tex.path = NULL;
	ctx->map.texture_list.west_tex.path = NULL;
	ctx->map.texture_list.east_tex.path = NULL;
}

void	free_map(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (!ctx->map.tile_list)
		return ;
	while (ctx->map.tile_list[i])
		free(ctx->map.tile_list[i++]);
	free(ctx->map.tile_list);
	ctx->map.tile_list = NULL;
}

static void	free_map_data(t_ctx *ctx)
{
	int	i;

	if (ctx->map.tile_list)
	{
		i = 0;
		while (ctx->map.tile_list[i])
		{
			free(ctx->map.tile_list[i]);
			i++;
		}
		free(ctx->map.tile_list);
	}
	free(ctx->map.texture_list.north_tex.path);
	free(ctx->map.texture_list.south_tex.path);
	free(ctx->map.texture_list.east_tex.path);
	free(ctx->map.texture_list.west_tex.path);
}

void	free_ctx(t_ctx *ctx, t_ctx **ref_ctx)
{
	if (!ctx)
		return ;
	free_map_data(ctx);
	destroy_textures_images(ctx, 3);
	if (ctx->win.ptr_mlx && ctx->win.img.ptr_img)
		mlx_destroy_image(ctx->win.ptr_mlx, ctx->win.img.ptr_img);
	if (ctx->win.ptr_mlx && ctx->win.ptr_win)
		mlx_destroy_window(ctx->win.ptr_mlx, ctx->win.ptr_win);
	if (ctx->win.ptr_mlx)
	{
		mlx_destroy_display(ctx->win.ptr_mlx);
		free(ctx->win.ptr_mlx);
	}
	free(*ref_ctx);
}
