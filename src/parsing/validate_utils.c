# include "../includes/cub3D.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_dir(t_game *game, char c)
{
	if (c == 'N')
		game->player.dir_x = 0, game->player.dir_y = -1,
		game->player.plane_x = 0.66, game->player.plane_y = 0;
	else if (c == 'S')
		game->player.dir_x = 0, game->player.dir_y = 1,
		game->player.plane_x = -0.66, game->player.plane_y = 0;
	else if (c == 'E')
		game->player.dir_x = 1, game->player.dir_y = 0,
		game->player.plane_x = 0, game->player.plane_y = 0.66;
	else if (c == 'W')
		game->player.dir_x = -1, game->player.dir_y = 0,
		game->player.plane_x = 0, game->player.plane_y = -0.66;
}

int	check_player(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map_parse.grid[y])
	{
		x = 0;
		while (game->map_parse.grid[y][x])
		{
			if (is_player(game->map_parse.grid[y][x]))
			{
				game->player.x = x;
				game->player.y = y;
				set_dir(game, game->map_parse.grid[y][x]);
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (print_error("Invalid player count.", NULL, 0));
	return (EXIT_SUCCESS);
}
