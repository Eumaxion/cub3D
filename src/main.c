#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	//t_game game;

	if (ac != 2)
	{
		write(2, "USAGE: ./cub3d map.cub\n", 24);
		return(1);
	}
	if (parse_cub(av[1]/* , &game */))
		return (1);
/* 	if (init_game(av))
		return (1);
	run_game(); */
	return (0);
}