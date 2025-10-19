#include "../include/ctx.h"
#include "../mlx_linux/mlx.h"
#include <math.h>

#define MOUSE_SENSITIVITY 0.003

static void	rotate_vector(t_ctx *ctx, double angle)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = ctx->player.direction.x;
	ctx->player.direction.x = cos(angle) * old_dir_x - sin(angle)
		* ctx->player.direction.y;
	ctx->player.direction.y = sin(angle) * old_dir_x + cos(angle)
		* ctx->player.direction.y;
	old_fov_x = ctx->player.fov.x;
	ctx->player.fov.x = cos(angle) * old_fov_x - sin(angle) * ctx->player.fov.y;
	ctx->player.fov.y = sin(angle) * old_fov_x + cos(angle) * ctx->player.fov.y;
}

int	handle_mouse(t_ctx *ctx)
{
	int		center_x;
	int		center_y;
	double	rotation;

	center_x = WINDOW_WIDTH / 2;
	center_y = WINDOW_HEIGHT / 2;
	if (!ctx->mouse_active)
		return (0);
	mlx_mouse_get_pos(ctx->win.ptr_mlx, ctx->win.ptr_win, &ctx->mouse_x,
		&ctx->mouse_y);
	ctx->mouse_step = ctx->mouse_x - center_x;
	if (ctx->mouse_step != 0)
	{
		rotation = ctx->mouse_step * MOUSE_SENSITIVITY;
		rotate_vector(ctx, rotation);
		mlx_mouse_move(ctx->win.ptr_mlx, ctx->win.ptr_win, center_x, center_y);
	}
	return (0);
}
