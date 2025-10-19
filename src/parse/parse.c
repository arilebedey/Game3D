#include "../../include/cleanup.h"
#include "../../include/ctx.h"
#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	parse(t_ctx *ctx, const char *file)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perr("Error\nInvalid file"), 0);
	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	ret = 0;
	while (line && !ret && *line != ' ' && *line != '1' && *line != '0')
	{
		ret = parse_identifier(ctx, line);
		free(line);
		line = get_next_line(fd);
		while (line && *line == '\n')
		{
			free(line);
			line = get_next_line(fd);
		}
	}
	if (ret)
	{
		close(fd);
		get_next_line(-1);
		free(line);
		free_textures(ctx);
		return (0);
	}
	if (!line)
		return (close(fd), free_textures(ctx), perr("Error\nMissing map"), 0);
	if (!load_map_lines(ctx, fd, line))
		return (close(fd), free_textures(ctx), 0);
	close(fd);
	get_next_line(-1);
	if (!validate_map(ctx))
		return (free_map(ctx), free_textures(ctx), 0);
	set_player_from_map(ctx);
	return (1);
}
