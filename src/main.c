#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return(print_error(USAGE_ERR));
	if (print_error(extension_test(av[1])))
		return (1);
	init_game(&game);
	if (parse_cub(av[1]/* , &game */))
		return (1);
	//run_game(&game);
	return (0);
}