/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:41:04 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/08 12:34:49 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_contain(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;
	int	num_c;

	i = 0;
	num_e = 0;
	num_p = 0;
	num_c = 0;
	while (i++ < ft_strlen(game->line))
	{
		if (game->line[i] == 'E')
			num_e++;
		else if (game->line[i] == 'P')
			num_p++;
		else if (game->line[i] == 'C')
			num_c++;
	}
	if (num_e != 1)
	    you_lose('E');
	if (num_c == 0)
        you_lose('C');
	if (num_p != 1)
	    you_lose('P');
	return (1);
}

int	check_path_e(t_game *game)
{
	int		fd;
	char	*line;
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
		return (1);
	return (0);
}