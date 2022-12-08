/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:28:21 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/08 11:28:22 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./map/map.h"
#include "./animation/animation.h"

void	sheck_maps(t_game *game)
{
	if (!map_contain(game) || !sheck_rectangular(game) || !check_path(game))
		exit_game(game);
	return ;
}

void	read_maps(t_game *game, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->line = ft_strdup_noline(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		game->line = ft_strjoin_so_long(game->line, line);
	}
	close(fd);
}

void	set_game(t_game *game, char *map)
{
	read_maps(game, map);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64 + 60, "so_long");
	sheck_maps(game);
	count_c(game);
	put_image(game);
	setting_img(game);
}
