/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:41:04 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/15 23:42:43 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_contain(t_game *game)
{
	int	i;
	int	num[3];

	i = 0;
	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	while (i < ft_strlen(game->line))
	{
		if (game->line[i] == 'E')
			num[0]++;
		else if (game->line[i] == 'P')
			num[1]++;
		else if (game->line[i] == 'C')
			num[2]++;
		i++;
	}
	if (num[0] != 1)
		you_lose('E', game);
	if (num[2] == 0)
		you_lose('C', game);
	if (num[1] != 1)
		you_lose('P', game);
	return (1);
}

int	check_map_bonus(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->line))
	{
		if (game->line[i] != 'E' && game->line[i] != 'P'
			&& game->line[i] != 'C' && game->line[i] != '1'
			&& game->line[i] != '0' && game->line[i] != 'A')
			return (0);
		i++;
	}
	return (1);
}

int	check_path_e(t_game *game)
{
	int		i;
	t_game	*tmp;

	tmp = malloc(sizeof(t_game));
	tmp->width = game->width;
	tmp->line = ft_strdup_m(game->line);
	i = 0;
	while (tmp->line[i] != '\0')
	{
		if (tmp->line[i] == 'E')
			tmp->line[i] = '1';
		i++;
	}
	if (check_path(tmp) == 1)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	you_lose('T', game);
	return (0);
}
