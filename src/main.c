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
int     close_hook(void *param)
{
	(void)param;
        printf("Game closed by window\n");
        exit(0);
}

int     key_press(int keycode, void *param)
{
    ((t_game *)param)->keys[keycode] = 1;
    if (keycode == XK_Escape)
        exit(0);
    return (0);
}

int     key_release(int keycode, void *param)
{
    ((t_game *)param)->keys[keycode] = 0;
    return (0);
}

int     render_loop(void *param)
{
    t_game *g = (t_game *)param;

    if (g->keys[XK_w] || g->keys[XK_W])  move_forward_back(g, 1);
    if (g->keys[XK_s] || g->keys[XK_S])  move_forward_back(g, -1);
    if (g->keys[XK_a] || g->keys[XK_A])  move_strafe(g, 1);
    if (g->keys[XK_d] || g->keys[XK_D])  move_strafe(g, -1);
    if (g->keys[XK_Left])                 rotate(g, -1);
    if (g->keys[XK_Right])                rotate(g, 1);
    render_frame(g);
    return (0);
}

int     main(int ac, char **av)
{
    t_game  g;

    (void)ac;
    (void)av;
    ft_memset(&g, 0, sizeof(t_game));
    init_game(&g);
    mlx_hook(g.win, 2, 1L<<0, (int(*)())key_press, &g);    // KeyPress
    mlx_hook(g.win, 3, 1L<<1, (int(*)())key_release, &g);  // KeyRelease
    mlx_hook(g.win, 17, 0, (int(*)())close_hook, &g);
    mlx_loop_hook(g.mlx, (int(*)())render_loop, &g);
    mlx_loop(g.mlx);
    return (0);
}
