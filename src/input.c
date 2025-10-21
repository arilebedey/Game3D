/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:43:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/21 11:45:03 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ctx.h"
#include <X11/keysym.h>

int	handle_key_press(int keysym, t_ctx *ctx)
{
	t_input	*ref_input;

	ref_input = &ctx->input;
	if (keysym == XK_w)
		ref_input->w = 1;
	if (keysym == XK_a)
		ref_input->a = 1;
	if (keysym == XK_s)
		ref_input->s = 1;
	if (keysym == XK_d)
		ref_input->d = 1;
	if (keysym == XK_Left)
		ref_input->left = 1;
	if (keysym == XK_Right)
		ref_input->right = 1;
	if (keysym == XK_Escape)
		ref_input->escape = 1;
	if (keysym == XK_Alt_L)
		ref_input->alt = 1;
	return (1);
}

int	handle_key_release(int keysym, t_ctx *ctx)
{
	t_input	*ref_input;

	ref_input = &ctx->input;
	if (keysym == XK_w)
		ref_input->w = 0;
	if (keysym == XK_a)
		ref_input->a = 0;
	if (keysym == XK_s)
		ref_input->s = 0;
	if (keysym == XK_d)
		ref_input->d = 0;
	if (keysym == XK_Left)
		ref_input->left = 0;
	if (keysym == XK_Right)
		ref_input->right = 0;
	if (keysym == XK_Escape)
		ref_input->escape = 0;
	if (keysym == XK_Alt_L)
		ref_input->alt = 0;
	return (1);
}
