/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:14:00 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:30:53 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_dir(char *arg)
{
	int	fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		ft_putstr_fd("\n", 2);
		ft_putendl_fd(arg, 2);
		close(fd);
		return (1);
	}
	return (0);
}

int	cub_extension(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (!i)
		return (1);
	while (file[i] != '.' && file[i] && i)
		--i;
	if (!file[i++] || file[i] != 'c')
		return (1);
	if (!file[i++] || file[i] != 'u')
		return (1);
	if (!file[i++] || file[i] != 'b')
		return (1);
	if (file[++i] != 0)
		return (1);
	return (0);
}

int	xpm_extension(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (!i)
		return (1);
	while (file[i] != '.' && file[i] && i)
		i--;
	if (!file[i++] || file[i] != 'x')
		return (1);
	if (!file[i++] || file[i] != 'p')
		return (1);
	if (!file[i++] || file[i] != 'm')
		return (1);
	if (file[++i] != 0)
		return (1);
	return (0);
}

int	file_test(char *file, int type)
{
	int	fd;

	if (type && cub_extension(file))
		return (print_error(EXTENSION_ERR, NULL, 0));
	if (!type && xpm_extension(file))
		return (print_error(XPM_ERROR, NULL, 0));
	if (is_dir(file))
		return (print_error(IS_DIRECTORY, NULL, 0));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(strerror(errno), NULL, 0));
	close(fd);
	return (EXIT_SUCCESS);
}

int	parse_cub(char *av, t_game *game)
{
	char	**file;

	if (file_test(av, CUB_FILE))
		return (EXIT_FAILURE);
	file = read_file(av);
	if (!file)
		return (EXIT_FAILURE);
	if (parse_elements(game, file))
		return (free_matrix(file), EXIT_FAILURE);
	if (parse_map(game, file))
		return (free_matrix(file), EXIT_FAILURE);
	if (validate_map(game))
		return (free_matrix(file), EXIT_FAILURE);
	free_matrix(file);
	return (EXIT_SUCCESS);
}
