#include "animation.h"

void move_monster_w(t_game *game,int i)
{
	if (game->line[i - game->width] == 'P')
		exit_game(game);
	if (game->line[i - game->width] != '1' && game->line[i - game->width] != 'C' && game->line[i - game->width] != 'E' && game->line[i - game->width] != 'A')
	{
		game->line[i] = '0';
		game->line[i - game->width] = 'A';
		put_image(game);
		setting_img(game);
	}
}
void move_monster_s(t_game *game,int i)
{
	if (game->line[i + game->width] == 'P')
		exit_game(game);
	if (game->line[i + game->width] != '1' && game->line[i + game->width] != 'C' && game->line[i + game->width] != 'E' && game->line[i + game->width] != 'A')
	{
		game->line[i] = '0';
		game->line[i + game->width] = 'A';
		put_image(game);
		setting_img(game);
	}
}
void move_monster_a(t_game *game,int i)
{
	if (game->line[i - 1] == 'P')
		exit_game(game);
	if (game->line[i - 1] != '1' && game->line[i - 1] != 'C' && game->line[i - 1] != 'E' && game->line[i - 1] != 'A')
	{
		game->line[i] = '0';
		game->line[i - 1] = 'A';
		put_image(game);
		setting_img(game);
	}
}
void move_monster_d(t_game *game,int i)
{
	if (game->line[i + 1] == 'P')
		exit_game(game);
	if (game->line[i + 1] != '1' && game->line[i + 1] != 'C' && game->line[i - 1] != 'E' && game->line[i + 1] != 'A')
	{
		game->line[i] = '0';
		game->line[i + 1] = 'A';
		put_image(game);
		setting_img(game);
	}
}