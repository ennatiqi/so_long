/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:21:59 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/06 10:34:35 by rennatiq         ###   ########.fr       */
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

void coin_animation(t_game *game)
{
	static int i;
	i++;

	if(i == 16001)
		i = 0;
	if (i == 2000)
	{
		game->path.path_item = "./assets/coin1.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 4000){
		game->path.path_item = "./assets/coin2.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 8000){
		game->path.path_item = "./assets/coin3.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 12000){
		game->path.path_item = "./assets/coin4.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 16000){
		game->path.path_item = "./assets/coin5.xpm";
		put_image(game);
		setting_img(game);
	}
}

void monstr_animation(t_game *game)
{
	static int i;
	i++;

	if(i == 12001)
		i = 0;
	if (i == 2000)
	{
		game->path.path_monstr = "./assets/mons1.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 4000){
		game->path.path_monstr = "./assets/mons2.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 8000){
		game->path.path_monstr = "./assets/mons3.xpm";
		put_image(game);
		setting_img(game);
	}
	else if (i == 12000){
		game->path.path_monstr = "./assets/mons4.xpm";
		put_image(game);
		setting_img(game);
	}
}

int     animation(void *game)
{
	t_game *play;
	play = game;
	coin_animation(play);
	monstr_animation(play);
	
	return (1);
}
