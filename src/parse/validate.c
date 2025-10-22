/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:53:06 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 12:20:58 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ctx.h"
#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../libft/libft.h"

static void	print_missing_wall_pos(int x, int y)
{
	ft_putstr_fd("Error\nMap not surrounded by walls at line ", 2);
	ft_putnbr_fd(y + 1, 2);
	ft_putstr_fd(", column ", 2);
	ft_putnbr_fd(x + 1, 2);
	ft_putchar_fd('\n', 2);
}

static int	validate_line_content(t_ctx *ctx, int y, int *player_count)
{
	int		x;
	char	c;

	x = 0;
	while (ctx->map.tile_list[y][x])
	{
		c = ctx->map.tile_list[y][x];
		if (!is_valid_tile(c))
		{
			ft_putstr_fd("Error\nInvalid character in map: '", 2);
			ft_putchar_fd(c, 2);
			ft_putstr_fd("'\n", 2);
			return (0);
		}
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			(*player_count)++;
		if (is_valid_tile(c) && c != '1' && c != ' ')
		{
			if (!is_surrounded_by_non_void(ctx, x, y))
				return (print_missing_wall_pos(x, y), 0);
		}
		x++;
	}
	return (1);
}

int	validate_map(t_ctx *ctx)
{
	int	player_count;
	int	y;

	player_count = 0;
	y = 0;
	while (ctx->map.tile_list && ctx->map.tile_list[y])
	{
		if (!is_line_empty(ctx->map.tile_list[y]) && !validate_line_content(ctx,
				y, &player_count))
			return (0);
		y++;
	}
	if (player_count == 0)
		return (perr("Error\nNo player in map"), 0);
	if (player_count > 1)
		return (perr("Error\nMultiple players in map"), 0);
	return (1);
}
