#ifndef RGB_H
# define RGB_H

#include <stdint.h>

typedef struct s_rgb
{
	__uint8_t	red;
	__uint8_t	green;
	__uint8_t	blue;
}			t_rgb;

// Returns the integer equivalent of a rgb.
int	encode_rgb(t_rgb rgb);

#endif
