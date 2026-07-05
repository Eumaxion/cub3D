/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:13:37 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/05 17:16:13 by mlima-si         ###   ########.fr       */
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
	/* para cada linha
    para cada caractere
        se não for um dos permitidos
            erro */
}

int	check_player(t_game *game)
{
	
}

int	check_closed(t_game *game)
{
	
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