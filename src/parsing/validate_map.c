/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:13:37 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:30:33 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_player(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

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

int	check_player(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map_parse.grid[y])
	{
		x = 0;
		while (game->map_parse.grid[y][x])
		{
			if (is_player(game->map_parse.grid[y][x]))
			{
				game->player.x = x;
				game->player.y = y;
				set_dir(game, game->map_parse.grid[y][x]);
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (print_error("Invalid player count.", NULL, 0));
	return (EXIT_SUCCESS);
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
