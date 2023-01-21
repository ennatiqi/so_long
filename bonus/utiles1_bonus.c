/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:12:01 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/21 16:43:44 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ifis_file(char *map)
{
	int		fd;

	fd = open(map, O_DIRECTORY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_rectangular(char *check, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (check[i])
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
		{
			if (count - 1 != size)
				return (0);
		}
	}
	free(check);
	return (1);
}

char	*read_norm(char *line, t_game *game)
{
	char	*check;

	check = ft_strdup_m(line);
	game->width = ft_strlen(line) - 1;
	if (game->width == 0)
		ft_error('T');
	game->line = ft_strdup_noline(line);
	return (check);
}

void	read_maps(t_game *game, char *map)
{
	int		fd;
	char	*line;
	char	*check;

	if (!check_ifis_file(map))
		ft_error('F');
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error('W');
	check = read_norm(line, game);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		check = ft_strjoin(check, line);
		game->line = ft_strjoin_so_long(game->line, line);
	}
	if (game->width > 40 || game->width < 2 || game->height > 30
		|| game->height < 2 || !check_rectangular(check, game->width))
	{
		//free(check);
		ft_error('R');
	}
	//free(check);
	close(fd);
}
