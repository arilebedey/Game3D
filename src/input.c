#include "../include/input.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <malloc.h>

int	handle_key_press(int keysym, t_input *ref_input)
{
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
	return (1);
}

int	handle_key_release(int keysym, t_input *ref_input)
{
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
	return (1);
}
