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

int     close_hook(void)
{
        printf("Game closed by window\n");
        exit(0);
}

int     main(int ac, char **av)
{
    void    *mlx;
    void    *win;

    (void)ac;
    (void)av;
    mlx = mlx_init();
    if (!mlx)
    {
        write(2, "mlx_init() failed\n", 18);
        return (1);
    }
    write(1, "mlx_init() ok\n", 14);
    win = mlx_new_window(mlx, 800, 600, "cub3D");
    if (!win)
    {
        write(2, "mlx_new_window() failed\n", 24);
        return (1);
    }
    write(1, "window created\n", 15);
    mlx_key_hook(win, key_hook, NULL);
    mlx_hook(win, 17, 0, close_hook, NULL);
    mlx_loop(mlx);
    return (0);
}
