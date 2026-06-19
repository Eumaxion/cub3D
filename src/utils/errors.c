# include "../includes/cub3D.h"

int	print_error(char *arg, t_game *game, int clean)
{
	write(2, "Error\n", 7);
	if (arg)
	{
		ft_pustr_fd(arg, 2);
		if (clean)
			clean_game(game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
