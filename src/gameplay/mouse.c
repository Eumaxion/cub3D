/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:46:36 by mlima-si          #+#    #+#             */
/*   Updated: 2026/09/08 12:06:27 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	mouse_handler(int x, int y, t_game *game)
{
	int	delta;

	(void)y;
	if (game->ignore_mouse)
	{
		game->ignore_mouse = 0;
		return (0);
	}
	delta = x - WIN_W / 2;
	if (delta > 10)
		delta = 10;
	if (delta < -10)
		delta = -10;
	if (delta != 0)
	{
		rotate(game, delta * MOUSE_SENSITIVITY);
		game->ignore_mouse = 1;
		mlx_mouse_move(game->mlx, game->win, WIN_W / 2, WIN_H / 2);
	}
	return (0);
}
