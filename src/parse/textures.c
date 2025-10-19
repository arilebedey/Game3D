#include "../../include/ctx.h"
#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	parse_textures(t_ctx *ctx, char *id, char *path)
{
	char	*trimmed;
	char	*full_path;

	if (!path)
		return (perr("Error\nInvalid texture path"), 1);
	trimmed = ft_strtrim(path, " \n\t\r");
	if (!trimmed)
		return (perr("Error\nmalloc failed"), 1);
	full_path = ft_strjoin("./", trimmed);
	free(trimmed);
	if (!full_path)
		return (perr("Error\nmalloc failed"), 1);
	if (!ft_strncmp(id, "NO", 3))
	{
		free(ctx->map.texture_list.north_tex.path);
		ctx->map.texture_list.north_tex.path = full_path;
	}
	else if (!ft_strncmp(id, "SO", 3))
	{
		free(ctx->map.texture_list.south_tex.path);
		ctx->map.texture_list.south_tex.path = full_path;
	}
	else if (!ft_strncmp(id, "WE", 3))
	{
		free(ctx->map.texture_list.west_tex.path);
		ctx->map.texture_list.west_tex.path = full_path;
	}
	else if (!ft_strncmp(id, "EA", 3))
	{
		free(ctx->map.texture_list.east_tex.path);
		ctx->map.texture_list.east_tex.path = full_path;
	}
	else
		return (free(full_path), perr("Error\nUnknown texture id"), 1);
	return (0);
}

int	parse_identifier(t_ctx *ctx, char *line)
{
	char	**split;
	int		ret;
	int		i;

	ret = 0;
	split = ft_split(line, ' ');
	if (!split || !split[0])
		return (perr("Error\nInvalid identifier"), 1);
	if (!ft_strncmp(split[0], "NO", 3))
		ret = parse_textures(ctx, "NO", split[1]);
	else if (!ft_strncmp(split[0], "SO", 3))
		ret = parse_textures(ctx, "SO", split[1]);
	else if (!ft_strncmp(split[0], "WE", 3))
		ret = parse_textures(ctx, "WE", split[1]);
	else if (!ft_strncmp(split[0], "EA", 3))
		ret = parse_textures(ctx, "EA", split[1]);
	else if (!ft_strncmp(split[0], "F", 2))
		ret = parse_rgb_value(&ctx->map.floor_color, split[1]);
	else if (!ft_strncmp(split[0], "C", 2))
		ret = parse_rgb_value(&ctx->map.ceiling_color, split[1]);
	else
		ret = (perr("Error\nWrong identifier"), 1);
	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
	return (ret);
}
