#include "../includes/cub3D.h"

/*int	main(int ac, char **av)
{
	if (ac==1)
		write(1,"ok\n", 4);
	else
		printf("%s\n", av[1]);
}*/

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307) // codigo ESC
	{
		printf("Game closed by user\n");
		exit(0);
	}
	return (0);
}

int     close_hook(void *param)
{
	(void)param;
        printf("Game closed by window\n");
        exit(0);
}

int	render_loop(void *param)
{
	render_frame((t_game *)param);
	return (0);
}

int     main(int ac, char **av)
{
	t_game  g;

	(void)ac;
	(void)av;
	ft_memset(&g, 0, sizeof(t_game));
	init_game(&g);
	mlx_key_hook(g.win, key_hook, &g);
	mlx_hook(g.win, 17, 0, close_hook, &g);
	mlx_loop_hook(g.mlx, render_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
