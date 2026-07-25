/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:38:01 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/25 17:20:59 by mlima-si         ###   ########.fr       */
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

void	init_textures(t_game *g)
{
	g->textures.north.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.north.path, &g->textures.w, &g->textures.h);
	g->textures.south.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.south.path, &g->textures.w, &g->textures.h);
	g->textures.west.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.west.path, &g->textures.w, &g->textures.h);
	g->textures.east.img = mlx_xpm_file_to_image(g->mlx,
			g->textures.east.path, &g->textures.w, &g->textures.h);
	g->textures.north.addr = mlx_get_data_addr(g->textures.north.img,
			&g->textures.north.bpp, &g->textures.north.line_len,
			&g->textures.north.endian);
	g->textures.south.addr = mlx_get_data_addr(g->textures.south.img,
			&g->textures.south.bpp, &g->textures.south.line_len,
			&g->textures.south.endian);
	g->textures.west.addr = mlx_get_data_addr(g->textures.west.img,
			&g->textures.west.bpp, &g->textures.west.line_len,
			&g->textures.west.endian);
	g->textures.east.addr = mlx_get_data_addr(g->textures.east.img,
			&g->textures.east.bpp, &g->textures.east.line_len,
			&g->textures.east.endian);
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
	return (EXIT_SUCCESS);
}
