# include "../includes/cub3D.h"

int clean_game(t_game *game)
{
	if (game)
	{
		printf("%d", game->colors.ceiling);
		return (1);
	}
	return (0);
}