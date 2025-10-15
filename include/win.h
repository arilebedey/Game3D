#ifndef WIN_H
# define WIN_H

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600

# define PI 3.14159265358979323846

#include "point.h"
#include "rgb.h"

typedef struct s_img
{
	void	*ptr_img;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_win
{
	void	*ptr_mlx;
	void	*ptr_win;
	t_img	img;
}			t_win;

// init.c

// Initalize mlx and window.
// If failed, prints error msg and returns 0.
int	init_window(t_win *ref_win);

// Initalize image data.
// If failed, prints error msg and returns 0.
int	init_image(t_win *ref_win);

#endif
