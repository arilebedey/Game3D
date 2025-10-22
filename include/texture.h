/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:17:02 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 13:17:03 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "win.h"

# define TEXTURE_SIZE -1

typedef struct s_ctx	t_ctx;

typedef struct s_texture
{
	t_img				img;
	char				*path;
	int					width;
	int					height;
}						t_texture;

// texture.c

// Loads all textures.
// If failed, prints error msg and returns 0.
int						load_textures(t_ctx *ctx);

// destroy all textures images.
// i = 0, destroy north
// i = 1, destroy north, south
// i = 2, destroy north, south , west
// i = 3, destroy north, south , west, east
void					destroy_textures_images(t_ctx *ctx, int i);

// pixel.c

// Returns the color value of a pixel in a texture.
int						get_texture_pixel(t_texture tex, int x, int y);

void					set_textures_size(t_ctx *ctx);

#endif
