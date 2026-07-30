/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:43:13 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/30 15:13:45 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_hook(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	printf("Game closed by window\n");
	clean_game(g);
	exit(0);
}

int	key_press(int keycode, void *param)
{
	if (keycode == XK_Escape)
	{
		clean_game((t_game *)param);
		exit(0);
	}
	if (keycode >= 0 && keycode < 65536)
		((t_game *)param)->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	if (keycode >= 0 && keycode < 65536)
		((t_game *)param)->keys[keycode] = 0;
	return (0);
}

int	render_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (g->keys[XK_w] || g->keys[XK_W])
		move_forward_back(g, 1);
	if (g->keys[XK_s] || g->keys[XK_S])
		move_forward_back(g, -1);
	if (g->keys[XK_a] || g->keys[XK_A])
		move_strafe(g, 1);
	if (g->keys[XK_d] || g->keys[XK_D])
		move_strafe(g, -1);
	if (g->keys[XK_Left])
		rotate(g, -1);
	if (g->keys[XK_Right])
		rotate(g, 1);
	if (g->player.moved == 0)
		return (0);
	render_frame(g);
	return (0);
}
