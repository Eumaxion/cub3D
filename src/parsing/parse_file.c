# include "../includes/cub3D.h"

int	is_dir(char *arg)
{
	int	fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}	

int	cub_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	while (file[i] != '.' && file[i] && i !=0)
		i--;
	if (!file[i] || file[++i] !=  'c')
		return (1);
	if (!file[i] || file[++i] !=  'u')
		return (1);
	if (!file[i] || file[++i] !=  'b')
		return (1);
	if (file[++i])
		return (1);
	return (0);
}

int	xpm_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	while (file[i] != '.' && file[i] && i !=0)
		i--;
	if (!file[i] || file[++i] !=  'x')
		return (1);
	if (!file[i] || file[++i] !=  'p')
		return (1);
	if (!file[i] || file[++i] !=  'm')
		return (1);
	if (file[++i])
		return (1);
	return (0);
}

int	file_test(char *file, int type)
{
	int	fd;

	if (is_dir(file))
		return (print_error(IS_DIRECTORY, NULL, 0));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(print_error(strerror(errno), NULL, 0));
	close(fd);
	if (type && cub_extension(file))
		return (print_error(EXTENSION_ERR, NULL, 0));
	if (!type && xpm_extension(file))
		return (print_error(XPM_ERROR, NULL, 0));
	return (EXIT_SUCCESS);
}
// open .cub;

// check only 0 1 orientation (N,E,S,W);
	//The map must be closed/surrounded by walls, if not the program must returnan error. (flod fill);
	//Except for the map content, each type of element can be separated by one or more empty lines.
	//Except for the map content which always has to be the last, each type of element can be set in any order in the file.
	//Except for the map, each type of information from an element can be separated by one or more spaces.
	//R,G,B colors in range [0,255]: 0, 255, 255

int	parse_cub(char *av, t_game *game)
{
	int	fd;

	if (file_test(av, CUB_FILE))
		return (EXIT_FAILURE);
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		return (print_error(strerror(errno), NULL, 0));
	init_map(game->map_parse);
	if (get_info(game, fd))
		return (EXIT_FAILURE);
	if (parse_textures(game, fd))
		return (EXIT_FAILURE);
	if (parse_colors(game, fd))
		return (EXIT_FAILURE);
	if (parse_map(game, fd))
		return (EXIT_FAILURE);
	if (flood_fill(game, fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
