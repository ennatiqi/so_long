/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:25:46 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/16 09:57:46 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_moster(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->line[i])
	{
		if (game->line[i] == 'A')
			count++;
		i++;
	}
	return (count);
}

void	set_monster(t_game *game)
{
	game->count_monster = count_moster(game);
	game->ex = malloc(game->count_monster * sizeof(int));
	if (!game->ex)
		you_lose('W');
}

void	monster_position(t_game *game)
{
	int	mon;
	int	m;

	mon = 0;
	m = 0;
	while (game->line[mon])
	{
		if (game->line[mon] == 'A')
		{
			game->ex[m] = mon;
			m++;
		}
		mon++;
	}
}
