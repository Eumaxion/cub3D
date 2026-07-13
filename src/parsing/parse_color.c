# include "../includes/cub3D.h"

static int	create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static int	parse_rgb(char *str, int *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (free_matrix(rgb), EXIT_FAILURE);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_matrix(rgb);
	if (r < 0 || r > 255)
		return (EXIT_FAILURE);
	if (g < 0 || g > 255)
		return (EXIT_FAILURE);
	if (b < 0 || b > 255)
		return (EXIT_FAILURE);
	*color = create_color(r, g, b);
	return (EXIT_SUCCESS);
}

int	parse_color(t_game *game, char *line)
{
	int		i;
	int		*color;

	i = skip_spaces(line);
	if (line[i] == 'F')
		color = &game->colors.floor;
	else
		color = &game->colors.ceiling;
	if (*color != -1)
		return (print_error("Duplicate color.", NULL, 0));
	i += 1;
	while (line[i] == ' ')
		i++;
	return (parse_rgb(line + i, color));
}
