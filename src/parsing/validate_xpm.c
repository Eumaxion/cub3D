#include "../includes/cub3D.h"

static int	validate_xpm(t_game *game, t_img *texture)
{
	int	width;
	int	height;
	void	*img;

	width = 0;
	height = 0;
	img = mlx_xpm_file_to_image(game->mlx, texture->path,
			&width, &height);
	if (!img)
		return (print_error(XPM_ERROR, NULL, 0));
	mlx_destroy_image(game->mlx, img);
	return (EXIT_SUCCESS);
}

int	validate_xpms(t_game *game)
{
	if (validate_xpm(game, &game->textures.north))
		return (EXIT_FAILURE);
	if (validate_xpm(game, &game->textures.south))
		return (EXIT_FAILURE);
	if (validate_xpm(game, &game->textures.west))
		return (EXIT_FAILURE);
	if (validate_xpm(game, &game->textures.east))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
