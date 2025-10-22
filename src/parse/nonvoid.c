/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonvoid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:44:13 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 13:44:34 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ctx.h"
#include "../../include/parse.h"

static int	has_non_void_adjacent_straight(t_ctx *ctx, int x, int y)
{
	char	left;
	char	right;
	char	up;
	char	down;

	left = get_tile_at(ctx, x - 1, y);
	right = get_tile_at(ctx, x + 1, y);
	up = get_tile_at(ctx, x, y - 1);
	down = get_tile_at(ctx, x, y + 1);
	return (!is_void(left) && !is_void(right) && !is_void(up)
		&& !is_void(down));
}

static int	has_non_void_adjacent_diagonal(t_ctx *ctx, int x, int y)
{
	char	top_left;
	char	top_right;
	char	bottom_left;
	char	bottom_right;

	top_left = get_tile_at(ctx, x - 1, y - 1);
	top_right = get_tile_at(ctx, x + 1, y - 1);
	bottom_left = get_tile_at(ctx, x - 1, y + 1);
	bottom_right = get_tile_at(ctx, x + 1, y + 1);
	return (!is_void(top_left) && !is_void(top_right) && !is_void(bottom_left)
		&& !is_void(bottom_right));
}

int	is_surrounded_by_non_void(t_ctx *ctx, int x, int y)
{
	return (has_non_void_adjacent_straight(ctx, x, y)
		&& has_non_void_adjacent_diagonal(ctx, x, y));
}
