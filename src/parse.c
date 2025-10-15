// paths des texture : ctx->map.texture_list.north_tex.path (dans le cas de la texture nord)

// Floor color : ctx->map.floor_color
// Ceiling color : ctx->map.ceiling_color
// (utiliser la fonction encode_rgb de la lib rgb.h pour convertir 3 valeurs rgb en un int🥸)

// Tilelist : ctx->map.tile_list
// Largeur max de la map : ctx->map.width
// hauteur max de la map : ctx->map.height

// Position du joueur : ctx->player.position
// Direction du joueur : ctx->player.direction
// Fov : ctx->player.fov

// Notes:
// Le vecteur fov est censer rester constamment perpendiculaire au vecteur de direction.
// Quand le joueur fait une rotation (modification du vecteur de direction), le vecteur fov doit suivre.
// Le fov sera de 66 degres. Donc pour une direction a (0, -1) (joueur regarde vers le nord), le fov sera de (0.66, 0).