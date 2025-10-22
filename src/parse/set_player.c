/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:09:37 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 13:09:37 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ctx.h"
#include <fcntl.h>
#include <unistd.h>

static void	set_player_direction(t_ctx *ctx, char c)
{
	if (c == 'N')
		ctx->player.direction = (t_vector2){0, -1.000001};
	else if (c == 'S')
		ctx->player.direction = (t_vector2){0, 1.000001};
	else if (c == 'E')
		ctx->player.direction = (t_vector2){1.000001, 0};
	else if (c == 'W')
		ctx->player.direction = (t_vector2){-1.000001, 0};
	ctx->player.fov.x = -ctx->player.direction.y * FOV_AMPLITUDE;
	ctx->player.fov.y = ctx->player.direction.x * FOV_AMPLITUDE;
}

void	set_player_from_map(t_ctx *ctx)
{
	char	c;
	int		y;
	int		x;

	y = 0;
	while (ctx->map.tile_list && ctx->map.tile_list[y])
	{
		x = 0;
		while (ctx->map.tile_list[y][x])
		{
			c = ctx->map.tile_list[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				ctx->player.position.x = x + 0.5;
				ctx->player.position.y = y + 0.5;
				set_player_direction(ctx, c);
				return ;
			}
			x++;
		}
		y++;
	}
}
