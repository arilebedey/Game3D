/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:20:13 by agense            #+#    #+#             */
/*   Updated: 2025/09/10 18:06:14 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/win.h"
#include "../../include/rgb.h"
#include "../../include/point.h"
#include "../../include/texture.h"
#include "../../include/error.h"
#include <stdlib.h>

void	img_pix_put(t_win win, int color, int x, int y)
{
	char	*pixel;
	int		i;

	if (x >= WINDOW_WIDTH || x < 0 || y >= WINDOW_WIDTH || y < 0)
		return ;
	pixel = win.img.address + (y * \
		win.img.line_len) \
			+ (x * (win.img.bpp / 8));
	i = win.img.bpp - 8;
	while (i >= 0)
	{
		if (win.img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (win.img.bpp \
				- 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	get_texture_pixel(t_texture tex, int x, int y)
{
	if (x < 0 || x >= tex.width || y < 0 \
		|| y >= tex.height)
	{
		perr("error: get_texture_pixel");
		exit(EXIT_FAILURE);
	}
	return (*(int *)(tex.img.address + (y * tex.img.line_len + x \
		* (tex.img.bpp / 8))));
}

// Returns the integer equivalent of a rgb.
int	encode_rgb(t_rgb rgb)
{
	return (rgb.red << 16 | rgb.green << 8 | rgb.blue);
}
