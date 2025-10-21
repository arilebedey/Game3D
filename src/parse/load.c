/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:01:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/21 12:07:44 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ctx.h"
#include "../../include/error.h"
#include "../../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	get_map_dimensions(t_list **lst, int fd, char *first_line,
		int *width)
{
	int		height;
	char	*line;

	height = 0;
	line = first_line;
	while (line)
	{
		if ((int)ft_strlen(line) > *width)
			*width = ft_strlen(line);
		ft_lstadd_back(lst, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
		line = get_next_line(fd);
		height++;
	}
	return (height);
}

static int	allocate_tile_list(t_ctx *ctx, t_list **lst, int height)
{
	ctx->map.tile_list = malloc(sizeof(char *) * (height + 1));
	if (!ctx->map.tile_list)
	{
		perr("Error\nmalloc failed");
		ft_lstclear(lst, free);
		return (0);
	}
	return (1);
}

static void	copy_list_to_array(t_ctx *ctx, t_list *lst, int height)
{
	t_list	*tmp;
	t_list	*next;
	int		i;

	tmp = lst;
	i = 0;
	while (i < height)
	{
		ctx->map.tile_list[i] = tmp->content;
		next = tmp->next;
		free(tmp);
		tmp = next;
		i++;
	}
	ctx->map.tile_list[height] = NULL;
}

int	load_map_lines(t_ctx *ctx, int fd, char *first_line)
{
	t_list	*lst;
	int		height;
	int		width;

	lst = NULL;
	width = 0;
	height = get_map_dimensions(&lst, fd, first_line, &width);
	if (!allocate_tile_list(ctx, &lst, height))
		return (0);
	copy_list_to_array(ctx, lst, height);
	return (1);
}
