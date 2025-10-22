/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:00:40 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 11:16:23 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "ctx.h"

int		parse(t_ctx *ctx, const char *file);

int		parse_rgb_value(int *dest, char *line);
void	set_player_from_map(t_ctx *ctx);
int		parse_identifier(t_ctx *ctx, char *line);
int		load_map_lines(t_ctx *ctx, int fd, char *first_line);
int		validate_map(t_ctx *ctx);

// utils.c
int		is_valid_tile(char c);
int		is_void(char c);
int		is_line_empty(char *line);
char	get_tile_at(t_ctx *ctx, int x, int y);
int		is_surrounded_by_non_void(t_ctx *ctx, int x, int y);

#endif
