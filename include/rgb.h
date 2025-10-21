/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:00:44 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/21 12:00:44 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

# include <stdint.h>

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;

// Returns the integer equivalent of a rgb.
int		encode_rgb(t_rgb rgb);

#endif
