#include "animation.h"

int	count_moster(t_game *game)
{
	int	i;
	int count = 0;

	i = 0;
	while (game->line[i])
	{
		if (game->line[i] == 'A')
			count++;
		i++;
	}
	return (count);
}

void	set_monster(t_game *game)
{
	game->count_monster = count_moster(game);
	game->ex = malloc(game->count_monster * sizeof(int));
}

void	monster_position(t_game *game)
{
	int mon;
	int m;
	mon = 0;
	m = 0;
	while (game->line[mon])
		{
			if (game->line[mon] == 'A')
			{
				game->ex[m] = mon;
				m++;
			}
			mon++;
		}
}