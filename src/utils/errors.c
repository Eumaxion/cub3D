# include "../includes/cub3D.h"

int	print_error(int error_code)
{
	write(2, "Error\n", 7);
	if (error_code == 6)
	{
		write(2, "USAGE: ./cub3d map.cub\n", 24);
		return (1);
	}
	if (error_code == 7)
	{
		write (2, "Invalid file, EXAMPLE.cub required.\n", 37);
		return (1);
	}
	return (0);
}