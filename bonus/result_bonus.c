/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:31:08 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/21 17:13:58 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	you_win(t_game *game)
{
	write(1, "YOU WIN", 7);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

void	ft_error(int c)
{
	if (c == 'A')
		write(2, "Error\ntry to use 2 argment", 26);
	if (c == 'F')
		write(2, "Error\ntry to use file not forlder", 33);
	if (c == 'R')
		write(2, "Error\ncheck that yor map is rectangular", 39);
	if (c == 'T')
		write(2, "Error\ntry to put map first think", 32);
	if (c == 'B')
		write(2, "Error\nyou need to push .ber file", 32);
	if (c == 'W')
		write(2, "Error\n", 6);
	exit(0);
	exit(0);
}

void	you_lose(int res, t_game *game)
{
	if (res == 'E')
		write(2, "Error\nyou need to have just one end!", 36);
	if (res == 'C')
		write(2, "Error\nyou need to have at least one collectible!", 48);
	if (res == 'P')
		write(2, "Error\nyou need to have just one start!", 38);
	if (res == 'T')
		write(2, "Error\ninvalide path!", 20);
	if (res == 'L')
		write(2, "YOU DEATH!", 16);
	if (res == 'N')
		write(2, "Error\ncheck your file name!", 27);
	if (res == 'Q')
		write(2, "Error\ncheck name of your xpm files", 34);
	if (res == 'W')
		write(2, "Error\n", 6);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
