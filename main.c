/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:11:04 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/21 12:07:18 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		ft_error('A');
	if (!check_ber(av[1]))
		ft_error('B');
	game = insert_to_game();
	game->mlx = mlx_init();
	set_game(game, av[1]);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 0, key_press, game);
	mlx_loop(game->mlx);
	return (0);
}
