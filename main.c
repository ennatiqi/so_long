/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:11:04 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/09 00:02:42 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./map/map.h"
#include "./animation/animation.h"

/* int	check_ber(char *str)
{
	int	l;
	int i;

	l = ft_strlen(str);
	i = l - 4;
	while (i < l)
	{
		str++;
		i++;
	}
	if ()
	return 1;
} */

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (0);
	/* if (!check_ber(av[1]))
		return (0); */
	game = insert_to_game();
	game->mlx = mlx_init();
	set_game(game, av[1]);
	set_monster(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 0, key_press, game);
	mlx_loop_hook(game->mlx, monster_move, game);
	mlx_loop(game->mlx);
	return (0);
}
