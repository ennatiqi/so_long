/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:31:11 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/03 15:34:22 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_ifisec_inmap(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'E' || line[i] == 'C')
			return (0);
		i++;
	}
	return (1);
}

char	*function(t_game *tmp, int i)
{
	if (tmp->line[i + 1] == '0' || tmp->line[i + 1] == 'E'
		|| tmp->line[i + 1] == 'C')
	{
		tmp->line[i + 1] = 'F';
		function(tmp, i + 1);
	}
	if (tmp->line[i - 1] == '0' || tmp->line[i - 1] == 'E'
		|| tmp->line[i - 1] == 'C')
	{
		tmp->line[i - 1] = 'F';
		function(tmp, i - 1);
	}
	if (tmp->line[i + tmp->width] == '0' || tmp->line[i + tmp->width] == 'E'
		|| tmp->line[i + tmp->width] == 'C')
	{
		tmp->line[i + tmp->width] = 'F';
		function(tmp, i + tmp->width);
	}
	if (tmp->line[i - tmp->width] == '0' || tmp->line[i - tmp->width] == 'E'
		|| tmp->line[i - tmp->width] == 'C')
	{
		tmp->line[i - tmp->width] = 'F';
		function(tmp, i - tmp->width);
	}
	return (tmp->line);
}

int	check_path(t_game *game)
{
	int		fd;
	char	*line;
	int		i;
	t_game	*tmp;

	tmp = malloc(sizeof(t_game));
	i = 0;
	fd = open("./maps/map.txt", O_RDONLY);
	line = get_next_line(fd);
	tmp->height = 0;
	tmp->width = ft_strlen(line) - 1;
	tmp->line = ft_strdup_noline(line);
	free(line);
	while (line)
	{
		tmp->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp->line = ft_strjoin_so_long(tmp->line, line);
	}
	close(fd);
	while (tmp->line[i] != '\0')
	{
		if (tmp->line[i] == 'P')
			break ;
		i++;
	}
	tmp->line[i] = 'F';
	tmp->line = function(tmp, i);
	if (check_ifisec_inmap(tmp->line) == 1)
		return (1);
	ft_printf("invalide path");
	return (0);
}

int	sheck_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->line))
	{	
		if (i < game->width)
		{
			if (game->line[i] != '1')
				return (0);
		}
		if (i % game->width == 0 || i % game->width == game->width - 1)
		{	
			if (game->line[i] != '1')
				return (0);
		}
		if (i > (ft_strlen(game->line) - game->width - 2))
		{
			if (game->line[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

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
	{
		ft_printf("you need to have just one end ");
		exit(0);
	}
	if (num_c == 0)
	{
		ft_printf("you need to have at least one collectible ");
		return (0);
	}
	if (num_p != 1)
	{
		ft_printf("you need to have just one start ");
		exit(0);
	}
	return (1);
}
