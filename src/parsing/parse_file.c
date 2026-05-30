# include "../includes/cub3D.h"

static int	extension_test(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.' && file[i])
		i++;
	if (!file[i] || file[++i] !=  'c')
		return (EXT_ERR);
	if (file[++i] !=  'u')
		return (EXT_ERR);
	if (file[++i] !=  'b')
		return (EXT_ERR);
	if (file[++i] != 0)
		return (EXT_ERR);
	return (0);
}

int	parse_cub(char *av/* , t_game *game */)
{
	if (print_error(extension_test(av)))
		return (1);
	return (0);
}