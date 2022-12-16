/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:28:52 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/16 10:23:07 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	put_image(t_game *game)
{
	int		width;
	int		height;

	height = game->height;
	width = game->width;
	game->img.avatar = mlx_xpm_file_to_image(game->mlx,
			game->path.path_avatar, &width, &height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			game->path.path_wall, &width, &height);
	game->img.item = mlx_xpm_file_to_image(game->mlx,
			game->path.path_item, &width, &height);
	game->img.door = mlx_xpm_file_to_image(game->mlx,
			game->path.path_door, &width, &height);
	game->img.imt = mlx_xpm_file_to_image(game->mlx,
			game->path.path_imt, &width, &height);
}

void	graph(t_game *game, int i, int j)
{
	if (game->line[(i * game->width) + j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, j * 64, i * 64);
	else if (game->line[(i * game->width) + j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.item, j * 64, i * 64);
	else if (game->line[(i * game->width) + j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.avatar, j * 64, i * 64);
	else if (game->line[(i * game->width) + j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.door, j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.imt, j * 64, i * 64);
}

void	setting_img(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			graph(game, i, j);
			j++;
		}
		i++;
	}
}

void	setting_img_bonus(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			graph(game, i, j);
			j++;
		}
		i++;
	}
	if (game->walk_word)
		mlx_string_put(game->mlx, game->win, 20,
			game->height * 64 + 20, 0x00000000, game->walk_word);
	game->walk_word = ft_itoa(game->walk_cnt);
	game->walk_word = ft_strjoin_walk("walking avatar : ", game->walk_word);
	mlx_string_put(game->mlx, game->win, 20,
		game->height * 64 + 20, 0x00FF0000, game->walk_word);
}