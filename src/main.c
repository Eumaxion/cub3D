#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return(print_error(USAGE_ERR));
	if (parse_cub(av[1]/* , &game */))
		return (1);
 	if (init_game(av, &game))
		return (1);
	run_game();
	return (0);
}