/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:21:59 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/05 13:15:42 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		move_w(game);
	else if (keycode == S_KEY)
		move_s(game);
	else if (keycode == A_KEY)
		move_a(game);
	else if (keycode == D_KEY)
		move_d(game);
	else if (keycode == ESC_KEY)
		exit(0);
	return (0);
}

void avatar_animation(t_game *game)
{
	static int i;
	i++;

	if(i == 4001)
		i = 0;
	if (i == 2000)
	{
		game->path.path_avatar = "./assets/avatar2.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 4000){
		game->path.path_avatar = "./assets/avatar.xpm";
		put_image(game);
		setting_img(game);
	}
}

int     animation(void *game)
{
	t_game *play;
	play = game;
	avatar_animation(play);
	return (1);
}
