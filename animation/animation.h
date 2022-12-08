/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:19:42 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/08 10:35:32 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "../so_long.h"
# include "../map/map.h"

void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
void	move_w(t_game *game);
int		key_press(int keycode, t_game *game);
int		animation(void *game);
void	move_monster_w(t_game *game, int i);
void	move_monster_s(t_game *game, int i);
void	move_monster_a(t_game *game, int i);
void	move_monster_d(t_game *game, int i);
void	set_monster(t_game *game);
void	monster_position(t_game *game);
int		monster_move(t_game *game);
char	*ft_itoa(int n);
char	*ft_strjoin_walk(char *s1, char *s2);

#endif