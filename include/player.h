#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"

# define ROTATION_SPEED 1
# define WALK_SPEED 1

typedef struct s_ctx	t_ctx;

typedef struct s_player
{
	t_vector2	position;
	t_vector2	fov;
	t_vector2	direction;
}		t_player;

// collision.c

// Prevents the player from going out of the map.
// Should be called just after player final position calculations.
void	borders_collision(t_ctx *ctx);

#endif
