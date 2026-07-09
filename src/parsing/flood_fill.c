# include "../includes/cub3D.h"

static char	**dup_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = ft_calloc(i + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_matrix(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

static int	is_outside(char **map, int x, int y)
{
	int	len;

	if (x < 0 || y < 0)
		return (1);
	if (!map[y])
		return (1);
	len = ft_strlen(map[y]);
	if (len > 0 && map[y][len - 1] == '\n')
		len--;
	if (x >= len)
		return (1);
	if (map[y][x] == ' ')
		return (1);
	return (0);
}

static int	flood(char **map, int x, int y)
{
	if (is_outside(map, x, y))
		return (1);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'F')
		return (0);
	map[y][x] = 'F';
	if (flood(map, x + 1, y))
		return (1);
	if (flood(map, x - 1, y))
		return (1);
	if (flood(map, x, y + 1))
		return (1);
	if (flood(map, x, y - 1))
		return (1);
	return (0);
}

int	check_closed(t_game *game)
{
	char	**copy;
	int		x;
	int		y;
	int		ret;

	copy = dup_map(game->map_parse.grid);
	if (!copy)
		return (EXIT_FAILURE);
	x = (int)game->player.x;
	y = (int)game->player.y;
	ret = flood(copy, x, y);
	free_matrix(copy);
	if (ret)
		return (print_error("Map is not closed.", NULL, 0));
	return (EXIT_SUCCESS);
}
