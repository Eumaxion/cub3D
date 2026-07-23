/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:14:11 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:31:08 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_map(t_map *map_parse)
{
	map_parse->grid = NULL;
	map_parse->map_index = 0;
	map_parse->width = 0;
	map_parse->height = 0;
}

static int	map_height(char **file, int start)
{
	int	height;

	height = 0;
	while (file[start + height])
		height++;
	return (height);
}

static int	map_width(char **map)
{
	int	i;
	int	width;
	int	len;

	i = 0;
	width = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len && map[i][len - 1] == '\n')
			len--;
		if (len > width)
			width = len;
		i++;
	}
	return (width);
}

static int	copy_map(t_game *game, char **file)
{
	int	i;
	int	j;

	game->map_parse.height = map_height(file,
			game->map_parse.map_index);
	game->map_parse.grid = ft_calloc(game->map_parse.height + 1,
			sizeof(char *));
	if (!game->map_parse.grid)
		return (EXIT_FAILURE);
	i = game->map_parse.map_index;
	j = 0;
	while (file[i])
	{
		game->map_parse.grid[j] = ft_strdup(file[i]);
		if (!game->map_parse.grid[j])
			return (EXIT_FAILURE);
		i++;
		j++;
	}
	game->map_parse.grid[j] = NULL;
	game->map_parse.width = map_width(game->map_parse.grid);
	return (EXIT_SUCCESS);
}

int	parse_map(t_game *game, char **file)
{
	return (copy_map(game, file));
}
