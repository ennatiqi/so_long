/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:31:03 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/04 13:48:19 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

int	count(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->line))
		if (game->line[i] == 'P')
			break ;
	return (i);
}

void	move_w(t_game *game)
{
	int		i;
	int		width;
	int		height;

	height = game->height;
	width = game->width;
	i = count(game);
	if (game->line[i - game->width] == 'C')
		game->col_cnt++;
	if (game->line[i - game->width] == 'C' && game->all_col == game->col_cnt)
		game->path.path_door = "./assets/exit.xpm";
	if (game->line[i - game->width] == 'E' && game->all_col == game->col_cnt)
		exit_game(game);
	else if (game->line[i - game->width] != '1'
		&& game->line[i - game->width] != 'E')
	{
		game->line[i] = '0';
		game->line[i - game->width] = 'P';
		game->walk_cnt++;
		put_image(game);
	setting_img(game);
	}
}

void	move_d(t_game *game)
{
	int		i;
	int		width;
	int		height;

	width = game->width;
	height = game->height;
	i = count(game);
	if (game->line[i + 1] == 'C')
		game->col_cnt++;
	if (game->line[i + 1] == 'C' && game->all_col == game->col_cnt)
		game->path.path_door = "./assets/exit.xpm";
	if (game->line[i + 1] == 'E' && game->all_col == game->col_cnt)
		exit_game(game);
	else if (game->line[i + 1] != '1' && game->line[i + 1] != 'E')
	{
		game->line[i] = '0';
		game->line[i + 1] = 'P';
		game->walk_cnt++;
		game->path.path_avatar = "./assets/avatar.xpm";
		put_image(game);
	setting_img(game);
	}
}

void	move_a(t_game *game)
{
	int		i;
	int		width;
	int		height;

	width = game->width;
	height = game->height;
	i = count(game);
	if (game->line[i - 1] == 'C')
		game->col_cnt++;
	if (game->line[i - 1] == 'C' && game->all_col == game->col_cnt)
		game->path.path_door = "./assets/exit.xpm";
	if (game->line[i - 1] == 'E' && game->all_col == game->col_cnt)
		exit_game(game);
	else if (game->line[i - 1] != '1' && game->line[i - 1] != 'E')
	{
		game->line[i] = '0';
		game->line[i - 1] = 'P';
		game->walk_cnt++;
		game->path.path_avatar = "./assets/avatar2.xpm";
		put_image(game);
	setting_img(game);
	}
}

void	move_s(t_game *game)
{
	int		i;
	int		width;
	int		height;

	height = game->height;
	width = game->width;
	i = count(game);
	if (game->line[i + game->width] == 'C')
		game->col_cnt++;
	if (game->line[i + game->width] == 'C' && game->all_col == game->col_cnt)
		game->path.path_door = "./assets/exit.xpm";
	if (game->line[i + game->width] == 'E' && game->all_col == game->col_cnt)
		exit_game(game);
	else if (game->line[i + game->width] != '1'
		&& game->line[i + game->width] != 'E')
	{
		game->line[i] = '0';
		game->line[i + game->width] = 'P';
		game->walk_cnt++;
		put_image(game);
	setting_img(game);
	}
}
