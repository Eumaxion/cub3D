/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:13:37 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/09 22:46:09 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3D.h"

int	is_valid_char(char c)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int	check_chars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_parse.grid[y])
	{
		x = 0;
		while (game->map_parse.grid[y][x])
		{
			if (!is_valid_char(game->map_parse.grid[y][x]))
				return (print_error("Invalid map character.", NULL, 0));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	validate_map(t_game *game)
{
	if (check_chars(game))
		return (EXIT_FAILURE);
	if (check_player(game))
		return (EXIT_FAILURE);
	if (check_closed(game))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
