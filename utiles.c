/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:30:09 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/07 16:08:29 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *base)
{
	int	count;

	count = 0;
	while (base[count])
		count++;
	return (count);
}

char	*ft_strdup_noline(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(ft_strlen(line));
	if (!tmp)
		return (0);
	while (i < ft_strlen(line) - 1)
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin_so_long(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*resulta;
	int		m;
	int		n;

	i = -1;
	if (!s1 || !s2)
		return (0);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	resulta = (char *)malloc((n + m) * sizeof(char));
	if (!resulta)
		return (0);
	while (++i < n)
		resulta[i] = s1[i];
	j = 0;
	while (s2[j] != '\0' && s2[j] != '\n')
		resulta[i++] = s2[j++];
	resulta[i] = 0;
	free(s1);
	free(s2);
	return (resulta);
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
	game->path.path_item = "./assets/coin1.xpm";
	game->path.path_door = "./assets/exit2.xpm";
	game->path.path_imt = "./assets/nothing.xpm";
	game->path.path_monstr = "./assets/mons1.xpm";
	return (game);
}
void	count_c(t_game *game)
{
	int		i;
	i = 0;
	while (i < game->width * game->height)
		if (game->line[i++] == 'C')
			game->all_col++;
}