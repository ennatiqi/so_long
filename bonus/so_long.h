/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennatiq <rennatiq@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:28:47 by rennatiq          #+#    #+#             */
/*   Updated: 2023/01/21 17:13:05 by rennatiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> 
# include "mlx.h"
//# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

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
	void	*monstr;
}		t_img;

typedef struct s_path
{
	char	*path_avatar;
	char	*path_wall;
	char	*path_item;
	char	*path_door;
	char	*path_imt;
	char	*path_monstr;
}	t_path;

typedef struct s_game
{
	char	*line;
	int		height;
	int		width;
	void	*mlx;
	void	*win;
	int		count_monster;
	int		*ex;
	t_img	img;
	t_path	path;
	int		col_cnt;
	int		walk_cnt;
	char	*walk_word;
	int		all_col;
}		t_game;

char	*ft_strjoin_so_long(char *s1, char *s2);
char	*ft_strdup_noline(char *line);
int		ft_strlen(char *base);
void	set_game(t_game *game, char *map);
void	set_game_bonus(t_game *game, char *map);
t_game	*insert_to_game(void);
void	count_c(t_game *game);
void	you_lose(int res, t_game *game);
void	you_win(t_game *game);
void	read_maps(t_game *game, char *map);

void	move_s_bonus(t_game *game);
void	move_a_bonus(t_game *game);
void	move_d_bonus(t_game *game);
void	move_w_bonus(t_game *game);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
void	move_w(t_game *game);
int		key_press_bonus(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		animation(void *game);
void	move_monster_w(t_game *game, int i);
void	move_monster_s(t_game *game, int i);
void	move_monster_a(t_game *game, int i);
void	move_monster_d(t_game *game, int i);
void	set_monster(t_game *game);
void	monster_position(t_game *game);
int		monster_move(t_game *game);
char	*ft_itoa(int n);
char	*ft_strjoin_walk(char *s1, char *s2);
void	ft_norminet(t_game *game, char *path_i, char *path_m);
void	ft_error(int c);
void	setting_img(t_game *game);
int		check_path(t_game *game);
void	put_image(t_game *game);
void	put_image_bonus(t_game *game);
void	setting_img_bonus(t_game *game);
int		sheck_rectangular(t_game *game);
int		map_contain(t_game *game);
int		exit_game(t_game *game);
char	*ft_strdup_m(char *s1);
int		check_path_e(t_game *game);
int		check_ber(char *str);
int		check_map(t_game *game);
int		check_map_bonus(t_game *game);
int		check_ifis_file(char *map);

#endif
