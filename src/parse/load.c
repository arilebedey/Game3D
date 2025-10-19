#include "../../include/ctx.h"
#include "../../include/error.h"
#include "../../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	load_map_lines(t_ctx *ctx, int fd, char *first_line)
{
	t_list	*lst;
	t_list	*tmp;
	int		height;
	int		width;
	t_list	*next;
	int		i;

	lst = NULL;
	height = 0;
	width = 0;
	while (first_line)
	{
		if (ft_strlen(first_line) > (size_t)width)
			width = ft_strlen(first_line);
		ft_lstadd_back(&lst, ft_lstnew(ft_strtrim(first_line, "\n")));
		free(first_line);
		first_line = get_next_line(fd);
		height++;
	}
	ctx->map.tile_list = malloc(sizeof(char *) * (height + 1));
	if (!ctx->map.tile_list)
		return (perr("Error\nmalloc failed"), ft_lstclear(&lst, free), 0);
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
	return (1);
}
