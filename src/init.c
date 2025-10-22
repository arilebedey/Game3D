/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:43:09 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 12:30:13 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ctx.h"
#include "../include/error.h"
#include "../include/win.h"
#include "../mlx_linux/mlx.h"
#include <X11/X.h>

int	init_window(t_win *ref_win)
{
	ref_win->ptr_mlx = mlx_init();
	if (!ref_win->ptr_mlx)
		return (perr("error: init mlx"), 0);
	ref_win->ptr_win = mlx_new_window(ref_win->ptr_mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cube 3 dimensions");
	if (!ref_win->ptr_win)
	{
		mlx_destroy_display(ref_win->ptr_mlx);
		return (perr("error: mlx_new_window"), 0);
	}
	return (1);
}

int	init_image(t_win *ref_win)
{
	ref_win->img.ptr_img = mlx_new_image(ref_win->ptr_mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!ref_win->img.ptr_img)
	{
		mlx_destroy_window(ref_win->ptr_mlx, ref_win->ptr_win);
		mlx_destroy_display(ref_win->ptr_mlx);
		return (perr("error: mlx_new_imagr"), 0);
	}
	ref_win->img.address = mlx_get_data_addr(ref_win->img.ptr_img,
			&ref_win->img.bpp, &ref_win->img.line_len, &ref_win->img.endian);
	if (!ref_win->img.address)
	{
		mlx_destroy_image(ref_win->ptr_mlx, ref_win->img.ptr_img);
		mlx_destroy_window(ref_win->ptr_mlx, ref_win->ptr_win);
		mlx_destroy_display(ref_win->ptr_mlx);
		return (perr("error: mlx_get_data_addr"), 0);
	}
	return (1);
}

void	init_input(t_input *ref_input)
{
	ref_input->w = 0;
	ref_input->a = 0;
	ref_input->s = 0;
	ref_input->d = 0;
	ref_input->left = 0;
	ref_input->right = 0;
	ref_input->escape = 0;
	ref_input->alt = 0;
}
