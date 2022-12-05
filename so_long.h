/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:28:47 by rennatiq          #+#    #+#             */
/*   Updated: 2022/12/05 13:08:14 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h> 
# include "mlx.h"
# include "ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct s_image
{
	void	*avatar;
	void	*wall;
	void	*item;
	void	*door;
	void	*imt;
	void	*adow;
}		t_img;

typedef struct s_path
{
	char	*path_avatar;
	char	*path_wall;
	char	*path_item;
	char	*path_door;
	char	*path_imt;
}	t_path;

typedef struct s_game
{
	char	*line;
	int		height;
	int		width;
	void	*mlx;
	void	*win;
	t_img	img;
	t_path	path;
	int		col_cnt;
	int		walk_cnt;
	int		all_col;
}		t_game;

char	*ft_strjoin_so_long(char *s1, char *s2);
char	*ft_strdup_noline(char *line);
int		ft_strlen(char *base);
void	set_game(t_game *game);

#endif