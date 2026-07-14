# include "../includes/cub3D.h"

int	print_error(char *arg, t_game *game, int clean)
{
	write(2, "Error\n", 6);
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		if (clean)
			clean_game(game);
		write(2, "\n", 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
