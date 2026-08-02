/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:47:45 by mlima-si          #+#    #+#             */
/*   Updated: 2026/08/02 16:19:35 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_wall(char **map, int x, int y)
{
	int	len;

	if (y < 0 || x < 0 || !map[y])
		return (1);
	len = (int)ft_strlen(map[y]);
	if (len > 0 && map[y][len - 1] == '\n')
		len--;
	if (x >= len)
		return (1);
	return (map[y][x] == '1');
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	get_tex_color(t_img *tex, int tex_x, int tex_y)
{
	char	*dst;

	dst = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

t_img	*get_wall_texture(t_game *g)
{
	t_ray	*r;

	r = &g->ray;
	if (r->side == 0)
	{
		if (r->raydir_x > 0)
			return (&g->textures.east);
		return (&g->textures.west);
	}
	if (r->raydir_y > 0)
		return (&g->textures.south);
	return (&g->textures.north);
}

void	draw_column(t_game *g, int x)
{
	t_draw	d;

	d.r = &g->ray;
	d.tex = get_wall_texture(g);
	d.step = 1.0 * g->textures.h / d.r->line_height;
	d.tex_pos = (d.r->draw_start - WIN_H / 2
			+ d.r->line_height / 2) * d.step;
	d.y = 0;
	while (d.y < d.r->draw_start)
		img_pixel_put(&g->screen, x, d.y++, g->colors.ceiling);
	while (d.y <= d.r->draw_end)
	{
		d.tex_y = (int)d.tex_pos & (g->textures.h - 1);
		d.tex_pos += d.step;
		d.color = get_tex_color(d.tex, d.r->textures_x, d.tex_y);
		img_pixel_put(&g->screen, x, d.y++, d.color);
	}
	while (d.y < WIN_H)
		img_pixel_put(&g->screen, x, d.y++, g->colors.floor);
}
