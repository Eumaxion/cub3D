# include "../includes/cub3D.h"

int	print_error(int error_nbr)
{
	if (error_nbr == 3)
	{
		write (2, "Invalid map\n", 13);
		return (1);
	}
	return (0);
}