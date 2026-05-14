#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	if (ac==1)
		write(1,"ok\n", 4);
	else
		printf("%s\n", av[1]);
}