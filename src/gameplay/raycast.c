/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:47:39 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/30 16:18:41 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	dda(t_game *g)
{
	t_ray	*r;

	r = &g->ray;
	r->hit = 0;
	while (!r->hit)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall(g->map, r->map_x, r->map_y))
			r->hit = 1;
		if (g->map[r->map_y][r->map_x] == 'M')
			r->special = 1;
		else
			r->special = 0;
	}
}

static void	calc_step_sidedist(t_game *g)
{
	t_ray		*r;
	t_player	*p;

	r = &g->ray;
	p = &g->player;
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (p->x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - p->x) * r->deltadist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (p->y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - p->y) * r->deltadist_y;
	}
}

static void	calc_texture(t_game *g)
{
	t_ray	*r;

	r = &g->ray;
	r->wall_x -= floor(r->wall_x);
	r->textures_x = (int)(r->wall_x * g->textures.w);
	if (r->textures_x < 0)
		r->textures_x = 0;
	if (r->textures_x >= g->textures.w)
		r->textures_x = g->textures.w - 1;
	if (r->side == 0 && r->raydir_x > 0)
		r->textures_x = g->textures.w - r->textures_x - 1;
	if (r->side == 1 && r->raydir_y < 0)
		r->textures_x = g->textures.w - r->textures_x - 1;
}

static void	calc_wall_height(t_game *g)
{
	t_ray		*r;
	t_player	*p;

	r = &g->ray;
	p = &g->player;
	if (r->side == 0)
	{
		r->perpwalldist = r->sidedist_x - r->deltadist_x;
		r->wall_x = p->y + r->perpwalldist * r->raydir_y;
	}
	else
	{
		r->perpwalldist = r->sidedist_y - r->deltadist_y;
		r->wall_x = p->x + r->perpwalldist * r->raydir_x;
	}
	calc_texture(g);
	r->line_height = (int)(WIN_H / r->perpwalldist);
	r->draw_start = WIN_H / 2 - r->line_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = WIN_H / 2 + r->line_height / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
}

void	render_frame(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		init_ray(g, x);
		calc_step_sidedist(g);
		dda(g);
		calc_wall_height(g);
		draw_column(g, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
/* 	if (BONUS)
		draw_minimap(); */
}
