/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:10:41 by alebedev          #+#    #+#             */
/*   Updated: 2025/10/22 13:10:41 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

// utils.c

// Swap the values of point1 and point2 between them.
void	swap_points(t_point *ref_point1, t_point *ref_point2);

#endif
