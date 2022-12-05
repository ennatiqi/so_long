#ifndef MAP_H
# define MAP_H

#include "../so_long.h"
# include <fcntl.h> 
# include "mlx.h"

void	setting_img(t_game *game);
int		check_path(t_game *game);
void	put_image(t_game *game);
int		sheck_rectangular(t_game *game);
int		map_contain(t_game *game);
int     exit_game(t_game *game);

#endif