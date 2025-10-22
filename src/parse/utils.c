/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:14:20 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 13:44:28 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ctx.h"
#include "../../include/parse.h"
#include "../../libft/libft.h"

int	is_valid_tile(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	is_void(char c)
{
	return (c == ' ' || c == '\0');
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	get_tile_at(t_ctx *ctx, int x, int y)
{
	if (y < 0 || !ctx->map.tile_list[y])
		return (' ');
	if (x < 0)
		return (' ');
	if ((int)ft_strlen(ctx->map.tile_list[y]) <= x)
		return (' ');
	return (ctx->map.tile_list[y][x]);
}
