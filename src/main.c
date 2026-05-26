#include "../includes/cub3D.h"

/*int	main(int ac, char **av)
{
	if (ac==1)
		write(1,"ok\n", 4);
	else
		printf("%s\n", av[1]);
}*/

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
        {
                write(2, "mlx_init() failed\n", 18);
                return (1);
        }
        write(1, "mlx_init() ok\n", 14);
        mlx_new_window(mlx, 800, 600, "Hello world");
        write(1, "window created\n", 15);
        mlx_loop(mlx);
}
