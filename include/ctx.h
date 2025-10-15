#ifndef CTX_H
# define CTX_H

# include "win.h"
# include "player.h"
# include "input.h"
# include "map.h"

typedef struct s_ctx
{
	t_win		win;
	t_player	player;
	t_map		map;
	t_input		input;
}		t_ctx;

#endif
