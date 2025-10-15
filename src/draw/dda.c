#include "../../include/ctx.h"
#include "../../include/draw.h"
#include "../../include/dda.h"
#include <math.h>

static t_vector2	get_ray(t_ctx *ctx, int col);
static void	init_dda(t_ctx *ctx, t_dda *ref_dda);
static void	raycast(t_ctx *ctx, t_dda *ref_dda);

void	dda_algo(t_ctx *ctx, t_dda *ref_dda)
{
	int		col;

	col = -1;
	while (++col < WINDOW_WIDTH)
	{
		ref_dda->ray = get_ray(ctx, col);
		ref_dda->tile.x = (int)ctx->player.position.x;
		ref_dda->tile.y = (int)ctx->player.position.y;
		if (ref_dda->ray.x == 0)
			ref_dda->delta_dist.x = 1e30;
		else
			ref_dda->delta_dist.x = fabs(1 / ref_dda->ray.x);
		if (ref_dda->ray.y == 0)
			ref_dda->delta_dist.y = 1e30;
		else
			ref_dda->delta_dist.y = fabs(1 / ref_dda->ray.y);
		init_dda(ctx, ref_dda);
		raycast(ctx, ref_dda);
		init_draw_elem(ctx, ref_dda, col);
	}
}

// Returns a ray according to the actual col.
static t_vector2	get_ray(t_ctx *ctx, int col)
{
	double	cameraX;
	t_vector2	ray;

	cameraX = 2 * col / (double)WINDOW_WIDTH - 1;
	ray.x = ctx->player.direction.x + ctx->player.fov.x * cameraX;
	ray.y = ctx->player.direction.y + ctx->player.fov.y * cameraX;
	return (ray);
}

// Initilaze dda struct.
static void	init_dda(t_ctx *ctx, t_dda *ref_dda)
{
	if (ref_dda->ray.x < 0)
	{
		ref_dda->step.x = -1;
		ref_dda->side_dist.x = (ctx->player.position.x - ref_dda->tile.x) \
			* ref_dda->delta_dist.x;
	}
	else
	{
		ref_dda->step.x = 1;
		ref_dda->side_dist.x = (ref_dda->tile.x + 1 - ctx->player.position.x) \
			* ref_dda->delta_dist.x;
	}
	if (ref_dda->ray.y < 0)
	{
		ref_dda->step.y = -1;
		ref_dda->side_dist.y = (ctx->player.position.y - ref_dda->tile.y) \
			* ref_dda->delta_dist.y;
	}
	else
	{
		ref_dda->step.y = 1;
		ref_dda->side_dist.y = (ref_dda->tile.y + 1 - ctx->player.position.y) \
			* ref_dda->delta_dist.y;
	}
}

// Cast the ray in dda.
// The tile struct will then contain the tile which have been hit.
static void	raycast(t_ctx *ctx, t_dda *ref_dda)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ref_dda->side_dist.x < ref_dda->side_dist.y)
		{
			ref_dda->side_dist.x += ref_dda->delta_dist.x;
			ref_dda->tile.x += ref_dda->step.x;
			ref_dda->side = 0;
		}
		else
		{
			ref_dda->side_dist.y += ref_dda->delta_dist.y;
			ref_dda->tile.y += ref_dda->step.y;
			ref_dda->side = 1;
		}
		if (ref_dda->tile.y < 0 || ref_dda->tile.y >= ctx->map.height || \
			ref_dda->tile.x < 0 || ref_dda->tile.x >= ctx->map.width || \
				ctx->map.tile_list[ref_dda->tile.y][ref_dda->tile.x] == '1')
			hit = 1;
	}
}
