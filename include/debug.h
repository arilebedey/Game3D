#ifndef DEBUG_H
# define DEBUG_H

# include "ctx.h"

// DEBUG MACROS
// Set these macros to 0 or 1 to disable or enable each debug functions.
// Do make fclean after setting.

# define DEBUG_INPUT 0

// Prints all pressed inputs.
// Need DEBUG_INPUT different to 0.
void	debug_input(t_input input);

#endif
