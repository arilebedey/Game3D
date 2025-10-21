/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:00:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/21 12:00:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include "ctx.h"

void	free_textures(t_ctx *ctx);
void	free_map(t_ctx *ctx);
void	free_ctx(t_ctx *ctx, t_ctx **ref_ctx);

#endif
