/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:14:18 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:14:23 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static char	*get_path(char *line)
{
	int		i;
	char	*path;

	i = skip_spaces(line);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	path = ft_strdup(line + i);
	if (!path)
		return (NULL);
	i = ft_strlen(path);
	if (i > 0 && path[i - 1] == '\n')
		path[i - 1] = '\0';
	return (path);
}

static int	set_texture(t_img *img, char *line)
{
	char	*path;

	if (img->path)
		return (print_error("Duplicate texture.", NULL, 0));
	path = get_path(line);
	if (!path)
		return (EXIT_FAILURE);
	if (file_test(path, XPM_FILE))
	{
		free(path);
		return (EXIT_FAILURE);
	}
	img->path = path;
	return (EXIT_SUCCESS);
}

int	parse_texture(t_game *game, char *line)
{
	int	i;

	i = skip_spaces(line);
	if (!ft_strncmp(line + i, "NO ", 3))
		return (set_texture(&game->textures.north, line));
	if (!ft_strncmp(line + i, "SO ", 3))
		return (set_texture(&game->textures.south, line));
	if (!ft_strncmp(line + i, "WE ", 3))
		return (set_texture(&game->textures.west, line));
	if (!ft_strncmp(line + i, "EA ", 3))
		return (set_texture(&game->textures.east, line));
	return (EXIT_FAILURE);
}
