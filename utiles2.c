/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:28:21 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/08 23:28:47 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./map/map.h"
#include "./animation/animation.h"

void	sheck_maps(t_game *game)
{
	if (!map_contain(game) || !sheck_rectangular(game) || !check_path(game) || !check_path_e(game))
		you_lose('T');
	return ;
}

int check_rectangular(char *check, int size)
{
	int i;
	int	count;

	i = 0;
	count = 1;
	while(check[i])
	{
		if (check[i] == '\n')
		{
			if (count - 1 != size)
				return (0);
			count = 0;
		}
		count++;
		i++;
		if (!check[i])
	    	if (count - 1 != size)
	            return 0;
	}
	return (1);
}

void	read_maps(t_game *game, char *map)
{
	int		fd;
	char	*line;
	char	*check;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	check = ft_strdup_m(line);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	if (game->width > 40)
		exit(0);
	game->line = ft_strdup_noline(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		check = ft_strjoin(check, line);
		game->line = ft_strjoin_so_long(game->line, line);
	}
	if (!check_rectangular(check, game->width))
		you_lose('T');
	free(check);
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
