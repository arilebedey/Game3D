/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:25:35 by agense            #+#    #+#             */
/*   Updated: 2025/09/08 22:37:12 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/point.h"

int	abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	swap_points(t_point *ref_point1, t_point *ref_point2)
{
	int	temp;

	temp = ref_point1->x;
	ref_point1->x = ref_point2->x;
	ref_point2->x = temp;
	temp = ref_point1->y;
	ref_point1->y = ref_point2->y;
	ref_point2->y = temp;
}

//void	clean_gnl_stash(int fd)
//{
//	char	*line;

//	line = get_next_line(fd);
//	while (line)
//	{
//		free(line);
//		line = get_next_line(fd);
//	}
//}

//int	split_len(char **split_s)
//{
//	int	i;

//	i = -1;
//	if (!split_s)
//		return (0);
//	while (split_s[++i])
//		;
//	return (i);
//}
