/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monstor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:20:22 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/23 12:29:54 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_monster_w(t_game *game, int i)
{
	if (game->line[i - game->width] == 'P')
		you_lose('L', game);
	if (game->line[i - game->width] != '1' && game->line[i - game->width] != 'C'
		&& game->line[i - game->width] != 'E'
		&& game->line[i - game->width] != 'A')
	{
		game->line[i] = '0';
		game->line[i - game->width] = 'A';
		put_image_bonus(game);
		setting_img_bonus(game);
	}
}

void	move_monster_s(t_game *game, int i)
{
	if (game->line[i + game->width] == 'P')
		you_lose('L', game);
	if (game->line[i + game->width] != '1' && game->line[i + game->width] != 'C'
		&& game->line[i + game->width] != 'E'
		&& game->line[i + game->width] != 'A')
	{
		game->line[i] = '0';
		game->line[i + game->width] = 'A';
		put_image_bonus(game);
		setting_img_bonus(game);
	}
}

void	move_monster_a(t_game *game, int i)
{
	if (game->line[i - 1] == 'P')
		you_lose('L', game);
	if (game->line[i - 1] != '1' && game->line[i - 1] != 'C'
		&& game->line[i - 1] != 'E' && game->line[i - 1] != 'A')
	{
		game->line[i] = '0';
		game->line[i - 1] = 'A';
		put_image_bonus(game);
		setting_img_bonus(game);
	}
}

void	move_monster_d(t_game *game, int i)
{
	if (game->line[i + 1] == 'P')
		you_lose('L', game);
	if (game->line[i + 1] != '1' && game->line[i + 1] != 'C'
		&& game->line[i - 1] != 'E' && game->line[i + 1] != 'A')
	{
		game->line[i] = '0';
		game->line[i + 1] = 'A';
		put_image_bonus(game);
		setting_img_bonus(game);
	}
}
