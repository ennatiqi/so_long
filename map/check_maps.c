/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:31:11 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/08 12:37:57 by rennatiq         ###   ########.fr       */
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
	free(line);
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

char	*ft_strdup_m(char *s1)
{
	int		i;
	char	*s2;
	char	*s3;

	i = 0;
	s2 = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	check_path(t_game *game)
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
		if (tmp->line[i] == 'P')
			break ;
		i++;
	}
	tmp->line[i] = 'F';
	tmp->line = function(tmp, i);
	if (check_ifisec_inmap(tmp->line) == 1)
		return (1);
	you_lose('T');
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
		if (i > (ft_strlen(game->line) - game->width))
		{
			if (game->line[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}
