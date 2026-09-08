/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:38:01 by mlima-si          #+#    #+#             */
/*   Updated: 2026/09/08 16:15:47 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//inicializa direcção e posição do raio para a coluna x
void	init_ray(t_game *g, int x)
{
	t_ray		*r;
	t_player	*p;

	r = &g->ray;
	p = &g->player;
	r->camera_x = 2.0 * x / WIN_W - 1.0;
	r->raydir_x = p->dir_x + p->plane_x * r->camera_x;
	r->raydir_y = p->dir_y + p->plane_y * r->camera_x;
	r->map_x = (int)p->x;
	r->map_y = (int)p->y;
	if (r->raydir_x == 0)
		r->deltadist_x = 1e30;
	else
		r->deltadist_x = fabs(1.0 / r->raydir_x);
	if (r->raydir_y == 0)
		r->deltadist_y = 1e30;
	else
		r->deltadist_y = fabs(1.0 / r->raydir_y);
}

static void	init_texture_addr(t_img *tex)
{
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp,
			&tex->line_len,
			&tex->endian);
}

void	init_textures(t_game *g)
{
	g->textures.north.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.north.path,
			&g->textures.north.width,
			&g->textures.north.height);
	g->textures.south.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.south.path,
			&g->textures.south.width,
			&g->textures.south.height);
	g->textures.west.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.west.path,
			&g->textures.west.width,
			&g->textures.west.height);
	g->textures.east.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.east.path,
			&g->textures.east.width,
			&g->textures.east.height);
	g->textures.player.img = mlx_xpm_file_to_image(g->mlx,
			"assets/textures/pug.xpm",
			&g->textures.player.width,
			&g->textures.player.height);
	init_texture_addr(&g->textures.north);
	init_texture_addr(&g->textures.south);
	init_texture_addr(&g->textures.west);
	init_texture_addr(&g->textures.east);
	init_texture_addr(&g->textures.player);
}

int	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (print_error(MLX_ERR, NULL, 0));
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	if (!g->win)
		return (print_error(MLX_FAIL, NULL, 0));
	g->screen.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->screen.addr = mlx_get_data_addr(g->screen.img,
			&g->screen.bpp, &g->screen.line_len, &g->screen.endian);
	if (BONUS)
	{
		mlx_mouse_move(g->mlx, g->win, WIN_W / 2, WIN_H / 2);
		mlx_mouse_hide(g->mlx, g->win);
	}
	return (EXIT_SUCCESS);
}
