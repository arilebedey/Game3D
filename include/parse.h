#ifndef PARSE_H
# define PARSE_H

# include "ctx.h"

int		parse(t_ctx *ctx, const char *file);

int		parse_rgb_value(int *dest, char *line);
void	set_player_from_map(t_ctx *ctx);
int		parse_identifier(t_ctx *ctx, char *line);
int		load_map_lines(t_ctx *ctx, int fd, char *first_line);
int		validate_map(t_ctx *ctx);

#endif
