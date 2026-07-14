#include "../includes/cub3D.h"

/* static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

void	print_game(t_game *game)
{
	printf("=== TEXTURES ===\n");
	printf("NO: %s\n", game->textures.north.path);
	printf("SO: %s\n", game->textures.south.path);
	printf("WE: %s\n", game->textures.west.path);
	printf("EA: %s\n", game->textures.east.path);

	printf("\n=== COLORS ===\n");
	printf("Floor: %d\n", game->colors.floor);
	printf("Ceiling: %d\n", game->colors.ceiling);

	printf("\n=== MAP ===\n");
	printf("Width : %d\n", game->map_parse.width);
	printf("Height: %d\n", game->map_parse.height);
	printf("Index : %d\n", game->map_parse.map_index);

	print_map(game->map_parse.grid);

	printf("\n=== PLAYER ===\n");
	printf("x = %.2f\n", game->player.x);
	printf("y = %.2f\n", game->player.y);
	printf("dir = (%.2f, %.2f)\n",
		game->player.dir_x, game->player.dir_y);
	printf("plane = (%.2f, %.2f)\n",
		game->player.plane_x, game->player.plane_y);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_error(USAGE_ERR, NULL, 0));
	init_game(&game);
	if (parse_cub(av[1], &game))
		return (clean_game(&game));
	print_game(&game);
	clean_game(&game);
	return (EXIT_SUCCESS);
} */
/* 
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
} */
int     main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return(print_error(USAGE_ERR, NULL, 0));
	init_game(&game);
	if (parse_cub(av[1], &game))
		return (clean_game(&game));
	if (init_mlx(&game))          // ← novo
		return (clean_game(&game));
	init_textures(&game);          // ← carrega xpm com os paths do parser
	game.map = game.map_parse.grid;
	game.player.x += 0.5;
	game.player.y += 0.5;
	mlx_hook(game.win, 2, 1L<<0, (int(*)())key_press, &game);    // KeyPress
	mlx_hook(game.win, 3, 1L<<1, (int(*)())key_release, &game);  // KeyRelease
	mlx_hook(game.win, 17, 0, (int(*)())close_hook, &game);
	mlx_loop_hook(game.mlx, (int(*)())render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
