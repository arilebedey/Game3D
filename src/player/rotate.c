/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:40:22 by agense            #+#    #+#             */
/*   Updated: 2025/10/22 12:40:39 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ctx.h"
#include "../../include/player.h"
#include <math.h>

// Returns fov value according to direction.
static t_vector2	calc_fov_vector(t_vector2 dir);

void	rotate_player(t_ctx *ctx)
{
	double	old_dir_x;
	double	rot_angle;

	rot_angle = 0;
	if (ctx->input.left)
		rot_angle = -ROT_SPEED;
	else if (ctx->input.right)
		rot_angle = ROT_SPEED;
	old_dir_x = ctx->player.direction.x;
	ctx->player.direction.x = ctx->player.direction.x * cos(rot_angle)
		- ctx->player.direction.y * sin(rot_angle);
	ctx->player.direction.y = old_dir_x * sin(rot_angle)
		+ ctx->player.direction.y * cos(rot_angle);
	ctx->player.fov = calc_fov_vector(ctx->player.direction);
}

static t_vector2	calc_fov_vector(t_vector2 dir)
{
	t_vector2	fov;

	fov.x = -dir.y * FOV_AMPLITUDE;
	fov.y = dir.x * FOV_AMPLITUDE;
	return (fov);
}
