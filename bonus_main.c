/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:12:08 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/16 10:17:34 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (0);
	if (!check_ber(av[1]))
		you_lose('N');
	game = insert_to_game();
	game->mlx = mlx_init();
	set_game_bonus(game, av[1]);
	set_monster(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 0, key_press_bonus, game);
	mlx_loop_hook(game->mlx, monster_move, game);
	mlx_loop(game->mlx);
	return (0);
}
