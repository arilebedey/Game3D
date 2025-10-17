#include "../../include/ctx.h"
#include "../../include/abs.h"
#include "../../include/player.h"
#include "../../include/vector.h"
#include <math.h>

// Set player's position according to inputs
static void	set_position_from_inputs(t_ctx *ctx);
// Collision handler
static void	handle_collision(t_ctx *ctx, t_vector2 old_pos);

void	move_player(t_ctx *ctx)
{
	t_vector2	old_pos;

	old_pos = ctx->player.position;
	set_position_from_inputs(ctx);
	handle_collision(ctx, old_pos);
}

static void	set_position_from_inputs(t_ctx *ctx)
{
	if (ctx->input.w)
	{
		ctx->player.position.x += ctx->player.direction.x * WALK_SPEED;
		ctx->player.position.y += ctx->player.direction.y * WALK_SPEED;
	}
	if (ctx->input.s)
	{
		ctx->player.position.x -= ctx->player.direction.x * WALK_SPEED;
		ctx->player.position.y -= ctx->player.direction.y * WALK_SPEED;
	}
	if (ctx->input.a)
	{
		ctx->player.position.x -= ctx->player.fov.x / \
			FOV_AMPLITUDE * WALK_SPEED;
		ctx->player.position.y -= ctx->player.fov.y / \
			FOV_AMPLITUDE * WALK_SPEED;
	}
	if (ctx->input.d)
	{
		ctx->player.position.x += ctx->player.fov.x / \
			FOV_AMPLITUDE * WALK_SPEED;
		ctx->player.position.y += ctx->player.fov.y / \
			FOV_AMPLITUDE * WALK_SPEED;
	}
}

static void	handle_collision(t_ctx *ctx, t_vector2 old_pos)
{
	if (ctx->map.tile_list[(int)ctx->player. \
		position.y][(int)ctx->player.position.x] == '1')
		ctx->player.position = old_pos;
}
