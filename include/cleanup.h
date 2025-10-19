#ifndef CLEANUP_H
# define CLEANUP_H

# include "ctx.h"

void	free_textures(t_ctx *ctx);
void	free_map(t_ctx *ctx);
void	free_ctx(t_ctx *ctx, t_ctx **ref_ctx);

#endif
