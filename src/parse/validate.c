#include "../../include/ctx.h"
#include "../../include/error.h"
#include "../../libft/libft.h"

static int	is_valid_tile(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

static int	is_void(char c)
{
	return (c == ' ' || c == '\0');
}

static char	get_tile_at(t_ctx *ctx, int x, int y)
{
	if (y < 0 || !ctx->map.tile_list[y])
		return (' ');
	if (x < 0 || !ctx->map.tile_list[y][x])
		return (' ');
	return (ctx->map.tile_list[y][x]);
}

static int	is_surrounded_by_non_void(t_ctx *ctx, int x, int y)
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

int	validate_map(t_ctx *ctx)
{
	int		y;
	int		x;
	char	c;
	int		player_count;

	y = 0;
	player_count = 0;
	while (ctx->map.tile_list && ctx->map.tile_list[y])
	{
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
				player_count++;
			if (is_valid_tile(c) && c != '1' && c != ' ')
			{
				if (!is_surrounded_by_non_void(ctx, x, y))
					return (perr("Error\nMap not surrounded by walls"), 0);
			}
			x++;
		}
		y++;
	}
	if (player_count == 0)
		return (perr("Error\nNo player in map"), 0);
	if (player_count > 1)
		return (perr("Error\nMultiple players in map"), 0);
	return (1);
}
