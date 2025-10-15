#ifndef INPUT_H
# define INPUT_H

typedef struct s_input
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
	int	escape;
}		t_input;

// init.c

// Init all input to zero.
void	init_input(t_input *ref_input);

// input.c

// Key pressed hook.
int	handle_key_press(int keysym, t_input *ref_input);
// Key released hook.
int	handle_key_release(int keysym, t_input *ref_input);

#endif
