/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:21:59 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/21 15:04:09 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_bonus(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		move_w_bonus(game);
	else if (keycode == S_KEY)
		move_s_bonus(game);
	else if (keycode == A_KEY)
		move_a_bonus(game);
	else if (keycode == D_KEY)
		move_d_bonus(game);
	else if (keycode == ESC_KEY)
		exit(0);
	return (0);
}

void	coin_animation(t_game *game)
{
	static int	i;

	i++;
	if (i == 16001)
		i = 0;
	if (i == 2000)
		ft_norminet(game, "./textures/coin1.xpm", "./textures/mons1.xpm");
	else if (i == 4000)
		ft_norminet(game, "./textures/coin2.xpm", "./textures/mons2.xpm");
	else if (i == 8000)
		ft_norminet(game, "./textures/coin3.xpm", "./textures/mons3.xpm");
	else if (i == 12000)
		ft_norminet(game, "./textures/coin4.xpm", "./textures/mons4.xpm");
	else if (i == 16000)
		ft_norminet(game, "./textures/coin5.xpm", "./textures/mons3.xpm");
}

int	animation(void *game)
{
	t_game	*play;

	play = game;
	coin_animation(play);
	return (1);
}

void	random_fun(t_game *game, int m)
{
	int	move;

	move = rand() % 4;
	if (move == 0)
		move_monster_w(game, game->ex[m]);
	else if (move == 1)
		move_monster_s(game, game->ex[m]);
	else if (move == 2)
		move_monster_a(game, game->ex[m]);
	else if (move == 3)
		move_monster_d(game, game->ex[m]);
}

int	monster_move(t_game *game)
{
	static int	i;
	int			m;

	i++;
	if (i == 5001)
		i = 0;
	if (i == 5000)
	{
		monster_position(game);
		m = 0;
		while (m < game->count_monster)
		{
			random_fun(game, m);
			m++;
		}
	}
	animation(game);
	return (1);
}
