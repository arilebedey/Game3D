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
