/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:12:08 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/21 12:08:36 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		ft_error('A');
	if (!check_ber(av[1]))
		ft_error('B');
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
