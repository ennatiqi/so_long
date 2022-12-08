/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:20:07 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/08 11:47:47 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../so_long.h"
# include <fcntl.h>
# include "mlx.h"

void	setting_img(t_game *game);
int		check_path(t_game *game);
void	put_image(t_game *game);
int		sheck_rectangular(t_game *game);
int		map_contain(t_game *game);
int		exit_game(t_game *game);
char	*ft_strdup_m(char *s1);
int	check_path_e(t_game *game);

#endif