#ifndef ANIMATION_H
# define ANIMATION_H

#include "../so_long.h"
#include "../map/map.h"

void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
void	move_w(t_game *game);
int		key_press(int keycode, t_game *game);
int     animation(void *game);


#endif