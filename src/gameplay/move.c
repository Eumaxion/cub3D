/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:47:32 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:47:35 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_forward_back(t_game *g, int dir)
{
	t_player	*p;
	double		new_x;
	double		new_y;

	p = &g->player;
	new_x = p->x + p->dir_x * MOV_SPEED * dir;
	new_y = p->y + p->dir_y * MOV_SPEED * dir;
	if (g->map[(int)p->y][(int)new_x] != '1')
		p->x = new_x;
	if (g->map[(int)new_y][(int)p->x] != '1')
		p->y = new_y;
}

void	move_strafe(t_game *g, int dir)
{
	t_player	*p;
	double		new_x;
	double		new_y;

	p = &g->player;
	new_x = p->x + p->dir_y * MOV_SPEED * dir;
	new_y = p->y - p->dir_x * MOV_SPEED * dir;
	if (g->map[(int)p->y][(int)new_x] != '1')
		p->x = new_x;
	if (g->map[(int)new_y][(int)p->x] != '1')
		p->y = new_y;
}

void	rotate(t_game *g, int dir)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;
	double		angle;

	p = &g->player;
	angle = ROT_SPEED * dir;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

/*int	key_handler(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keycode == XK_Escape)
	{
		printf("Game closed!\n");
		exit(0);
	}
	else if (keycode == XK_w || keycode == XK_W)
		move_forward_back(g, 1);
	else if (keycode == XK_s || keycode == XK_S)
		move_forward_back(g, -1);
	else if (keycode == XK_a || keycode == XK_A)
		move_strafe(g, -1);
	else if (keycode == XK_d || keycode == XK_D)
		move_strafe(g, 1);
	else if (keycode == XK_Left)
		rotate(g, 1);
	else if (keycode == XK_Right)
		rotate(g, -1);
	return (0);
}*/
