#include "../include/debug.h"
#include "../libft/libft.h"
#include <X11/X.h>

void	debug_input(t_input input)
{
	if (!DEBUG_INPUT)
		return ;
	ft_printf("debug input: ");
	if (input.w)
		ft_printf("W ");
	if (input.a)
		ft_printf("A ");
	if (input.s)
		ft_printf("S ");
	if (input.d)
		ft_printf("D ");
	if (input.left)
		ft_printf("Left ");
	if (input.right)
		ft_printf("Right ");
	if (input.escape)
		ft_printf("Escape ");
	ft_printf("\n");
}
