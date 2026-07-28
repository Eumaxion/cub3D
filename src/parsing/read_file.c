/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:14:35 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:15:50 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	matrix_size(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

static char	**matrix_add(char **matrix, char *line)
{
	char	**new;
	int		size;
	int		i;

	size = matrix_size(matrix);
	new = ft_calloc(size + 2, sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = matrix[i];
		i++;
	}
	new[size] = ft_strdup(line);
	new[size + 1] = NULL;
	free(matrix);
	return (new);
}

char	**read_file(char *path)
{
	char	*line;
	char	**file;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error(strerror(errno), NULL, 0);
		return (NULL);
	}
	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		file = matrix_add(file, line);
		free(line);
		if (!file)
		{
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (file);
}
