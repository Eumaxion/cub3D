/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:47:32 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/30 16:44:09 by mlima-si         ###   ########.fr       */
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
	if (!is_wall(g->map, (int)new_x, (int)p->y))
		p->x = new_x;
	if (!is_wall(g->map, (int)p->x, (int)new_y))
		p->y = new_y;
	g->player.moved = 1;
}

void	move_strafe(t_game *g, int dir)
{
	t_player	*p;
	double		new_x;
	double		new_y;

	p = &g->player;
	new_x = p->x + p->dir_y * MOV_SPEED * dir;
	new_y = p->y - p->dir_x * MOV_SPEED * dir;
	if (!is_wall(g->map, (int)new_x, (int)p->y))
		p->x = new_x;
	if (!is_wall(g->map, (int)p->x, (int)new_y))
		p->y = new_y;
	g->player.moved = 1;
}

void	rotate(t_game *g, double angle)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &g->player;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
	p->moved = 1;
}

/* void	rotate(t_game *g, int dir)
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
	g->player.moved = 1;
} */
