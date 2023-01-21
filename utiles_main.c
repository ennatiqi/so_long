/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:28:21 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/20 15:14:26 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sheck_maps(t_game *game)
{
	if (!map_contain(game) || !sheck_rectangular(game) || !check_path(game)
		|| !check_path_e(game) || !check_map(game))
		you_lose('T', game);
	return ;
}

void	set_game(t_game *game, char *map)
{
	read_maps(game, map);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	sheck_maps(game);
	count_c(game);
	put_image(game);
	setting_img(game);
}
