/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:17:07 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/20 15:40:17 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		game->path.path_door = "./textures/exit.xpm";
	if (game->line[i - game->width] == 'E' && game->all_col == game->col_cnt)
		you_win(game);
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
		game->path.path_door = "./textures/exit.xpm";
	if (game->line[i + 1] == 'E' && game->all_col == game->col_cnt)
		you_win(game);
	else if (game->line[i + 1] != '1' && game->line[i + 1] != 'E')
	{
		game->line[i] = '0';
		game->line[i + 1] = 'P';
		game->walk_cnt++;
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
		game->path.path_door = "./textures/exit.xpm";
	if (game->line[i - 1] == 'E' && game->all_col == game->col_cnt)
		you_win(game);
	else if (game->line[i - 1] != '1' && game->line[i - 1] != 'E')
	{
		game->line[i] = '0';
		game->line[i - 1] = 'P';
		game->walk_cnt++;
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
		game->path.path_door = "./textures/exit.xpm";
	if (game->line[i + game->width] == 'E' && game->all_col == game->col_cnt)
		you_win(game);
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
