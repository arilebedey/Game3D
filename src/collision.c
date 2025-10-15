#include "../include/ctx.h"

void	borders_collision(t_ctx *ctx)
{
	if (ctx->player.position.x < 1.01)
		ctx->player.position.x = 1.01;
	if (ctx->player.position.x > ctx->map.width - 1.01)
		ctx->player.position.x = ctx->map.width - 1.01;
	if (ctx->player.position.y < 1.01)
		ctx->player.position.y = 1.01;
	if (ctx->player.position.y > ctx->map.height - 1.01)
		ctx->player.position.y = ctx->map.height - 1.01;
}
