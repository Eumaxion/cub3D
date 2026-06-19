#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return(print_error(USAGE_ERR, NULL, 0));
	init_game(&game);
	if (parse_cub(av[1], &game))
		return (clean_game(&game));
	//run_game(&game);
	return (EXIT_SUCCESS);
}
