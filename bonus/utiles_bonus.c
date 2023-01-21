/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:13:57 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/23 12:30:12 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_norminet(t_game *game, char *path_i, char *path_m)
{
	game->path.path_item = path_i;
	game->path.path_monstr = path_m;
	put_image_bonus(game);
	setting_img_bonus(game);
}

void	sheck_maps_bonus(t_game *game)
{
	if (!map_contain(game) || !sheck_rectangular(game) || !check_path(game)
		|| !check_path_e(game) || !check_map_bonus(game))
		you_lose('T', game);
	return ;
}

void	set_game_bonus(t_game *game, char *map)
{
	read_maps(game, map);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64 + 60, "so_long");
	sheck_maps_bonus(game);
	count_c(game);
	put_image_bonus(game);
	setting_img_bonus(game);
}
