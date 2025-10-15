#include "../include/texture.h"
#include "../include/ctx.h"
#include "../include/error.h"
#include "../mlx_linux/mlx.h"
#include <X11/X.h>

static int	load(t_ctx *ctx, t_texture *ref_tex, int i);

int	load_textures(t_ctx *ctx)
{
	if (!load(ctx, &ctx->map.texture_list.north_tex, 0))
		return (0);
	if (!load(ctx, &ctx->map.texture_list.south_tex, 1))
		return (0);
	if (!load(ctx, &ctx->map.texture_list.west_tex, 2))
		return (0);
	if (!load(ctx, &ctx->map.texture_list.east_tex, 3))
		return (0);
	return (1);
}

void	destroy_textures_images(t_ctx *ctx, int i)
{
	if (i >= 0 && ctx->map.texture_list.north_tex.img.ptr_img)
		mlx_destroy_image(ctx->win.ptr_mlx, \
			ctx->map.texture_list.north_tex.img.ptr_img);
	if (i >= 1 && ctx->map.texture_list.south_tex.img.ptr_img)
		mlx_destroy_image(ctx->win.ptr_mlx, \
			ctx->map.texture_list.south_tex.img.ptr_img);
	if (i >= 2 && ctx->map.texture_list.west_tex.img.ptr_img)
		mlx_destroy_image(ctx->win.ptr_mlx, \
			ctx->map.texture_list.west_tex.img.ptr_img);
	if (i >= 3 && ctx->map.texture_list.east_tex.img.ptr_img)
		mlx_destroy_image(ctx->win.ptr_mlx, \
			ctx->map.texture_list.east_tex.img.ptr_img);
}

// load a texture img
// If failed, destroy all textures images and prints error msg and returns 0.
static int	load(t_ctx *ctx, t_texture *ref_tex, int i)
{
	ref_tex->img.ptr_img = mlx_xpm_file_to_image(ctx->win.ptr_mlx, \
		ref_tex->path, &ref_tex->width, &ref_tex->height);
	if (!ref_tex->img.ptr_img)
		return (perr("fail load texture"), 0);
	ref_tex->img.address = mlx_get_data_addr(ref_tex->img.ptr_img, \
		&ref_tex->img.bpp, &ref_tex->img.line_len, \
			&ref_tex->img.endian);
	if (!ref_tex->img.address)
		return (perr("fail get addr"), destroy_textures_images(ctx, i), 0);
	return (1);
}
