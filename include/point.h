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
