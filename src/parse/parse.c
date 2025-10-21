/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:07:50 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/21 12:11:31 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cleanup.h"
#include "../../include/ctx.h"
#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perr("Error\nInvalid file");
		return (-1);
	}
	return (fd);
}

static char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	parse_identifiers(t_ctx *ctx, int fd, char **line)
{
	int	ret;

	ret = 0;
	while (*line && !ret && **line != ' ' && **line != '1' && **line != '0')
	{
		ret = parse_identifier(ctx, *line);
		free(*line);
		*line = get_next_line(fd);
		while (*line && **line == '\n')
		{
			free(*line);
			*line = get_next_line(fd);
		}
	}
	return (ret);
}

static int	load_and_validate_map(t_ctx *ctx, int fd, char *line)
{
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

int	parse(t_ctx *ctx, const char *file)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open_file(file);
	if (fd < 0)
		return (0);
	line = skip_empty_lines(fd);
	ret = parse_identifiers(ctx, fd, &line);
	if (ret)
	{
		close(fd);
		get_next_line(-1);
		free(line);
		free_textures(ctx);
		return (0);
	}
	return (load_and_validate_map(ctx, fd, line));
}
