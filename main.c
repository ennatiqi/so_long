/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:11:04 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/05 13:01:57 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./map/map.h"
#include "./animation/animation.h"

void	sheck_maps(t_game *game)
{
	if (!map_contain(game) || !sheck_rectangular(game) || !check_path(game))
		exit_game(game);
	return ;
}

void	read_maps(t_game *game)
{
	int		fd;
	char	*line;

	fd = open("./maps/map.txt", O_RDONLY);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->line = ft_strdup_noline(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		game->line = ft_strjoin_so_long(game->line, line);
	}
	close(fd);
}

void	count_c(t_game *game)
{
	int		i;
	i = 0;
	while (i < game->width * game->height)
		if (game->line[i++] == 'C')
			game->all_col++;
}

void	set_game(t_game *game)
{
	read_maps(game);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	sheck_maps(game);
	count_c(game);
	put_image(game);
	setting_img(game);
}

t_game	*insert_to_game()
{
	t_game	*game;
	game = (t_game *)malloc(sizeof(t_game));
	game->col_cnt = 0;
	game->all_col = 0;
	game->walk_cnt = 0;
	game->path.path_avatar = "./assets/avatar.xpm";
	game->path.path_wall = "./assets/wall.xpm";
	game->path.path_item = "./assets/c.xpm";
	game->path.path_door = "./assets/exit2.xpm";
	game->path.path_imt = "./assets/nothing.xpm";
	return (game);
}

int	main(void)
{
	t_game	*game;
	game = insert_to_game();
	game->mlx = mlx_init();
	set_game(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
	return (0);
}