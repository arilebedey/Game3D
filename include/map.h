/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:12:05 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 13:12:05 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "rgb.h"
# include "texture.h"
# include "win.h"

typedef struct s_texture_list
{
	t_texture		north_tex;
	t_texture		south_tex;
	t_texture		west_tex;
	t_texture		east_tex;
}					t_texture_list;

typedef struct s_map
{
	char			**tile_list;
	int				floor_color;
	int				ceiling_color;
	t_texture_list	texture_list;
}					t_map;

#endif
