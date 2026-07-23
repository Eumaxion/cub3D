/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:13:43 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:13:47 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int	is_empty_line(char *line)
{
	int	i;

	i = skip_spaces(line);
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

int	is_texture(char *line)
{
	int	i;

	i = skip_spaces(line);
	if (!ft_strncmp(line + i, "NO ", 3))
		return (1);
	if (!ft_strncmp(line + i, "SO ", 3))
		return (1);
	if (!ft_strncmp(line + i, "WE ", 3))
		return (1);
	if (!ft_strncmp(line + i, "EA ", 3))
		return (1);
	return (0);
}

int	is_color(char *line)
{
	int	i;

	i = skip_spaces(line);
	if (!ft_strncmp(line + i, "F ", 2))
		return (1);
	if (!ft_strncmp(line + i, "C ", 2))
		return (1);
	return (0);
}

int	parse_elements(t_game *game, char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (is_empty_line(file[i]))
			i++;
		else if (is_texture(file[i]))
		{
			if (parse_texture(game, file[i]))
				return (EXIT_FAILURE);
			i++;
		}
		else if (is_color(file[i]))
		{
			if (parse_color(game, file[i]))
				return (EXIT_FAILURE);
			i++;
		}
		else
			break ;
	}
	game->map_parse.map_index = i;
	return (EXIT_SUCCESS);
}
