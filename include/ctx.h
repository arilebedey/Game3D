#ifndef CTX_H
# define CTX_H

# include "map.h"
# include "player.h"
# include "win.h"

typedef struct s_input
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			right;
	int			left;
	int			escape;
}				t_input;

typedef struct s_ctx
{
	t_win		win;
	t_player	player;
	t_map		map;
	t_input		input;
	int			mouse_active;
	int			mouse_x;
	int			mouse_y;
	int			mouse_step;
}				t_ctx;

// Mouse movements.
int				handle_mouse(t_ctx *ctx);
// Init all input to zero.
void			init_input(t_input *ref_input);
// Key pressed hook.
int				handle_key_press(int keysym, t_ctx *ctx);
// Key released hook.
int				handle_key_release(int keysym, t_ctx *ctx);

#endif
