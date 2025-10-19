#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"

# define WALK_SPEED 0.05
# define ROT_SPEED 0.025
# define FOV_AMPLITUDE 0.5

typedef struct s_ctx	t_ctx;

typedef struct s_player
{
	t_vector2			position;
	t_vector2			fov;
	t_vector2			direction;
}						t_player;

// Rotate player according to inputs.
void					rotate_player(t_ctx *ctx);

// Move player according to inputs.
void					move_player(t_ctx *ctx);

#endif
