# include "../includes/cub3D.h"

static int	extension_test(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.' && file[i])
		i++;
	if (!file[i] || file[++i] !=  'c')
		return (EXTENSION_ERR);
	if (file[++i] !=  'u')
		return (EXTENSION_ERR);
	if (file[++i] !=  'b')
		return (EXTENSION_ERR);
	if (file[++i] != 0)
		return (EXTENSION_ERR);
	return (0);
}
// open .cub;

// check only 0 1 orientation (N,E,S,W);
	//The map must be closed/surrounded by walls, if not the program must returnan error. (flod fill);
	//Except for the map content, each type of element can be separated by one or more empty lines.
	//Except for the map content which always has to be the last, each type of element can be set in any order in the file.
	//Except for the map, each type of information from an element can be separated by one or more spaces.
	//R,G,B colors in range [0,255]: 0, 255, 255

int	parse_cub(char *av/* , t_game *game */)
{
	if (print_error(extension_test(av)))
		return (1);
	if (print_error(parse_textures(av)))
		return (1);
	if (print_error(parse_colors(av)))
		return (1);
	if (print_error(validate_map(av)))
		return (1);
	if (print_error(flood_fill(av)))
		return (1);
	return (0);
}