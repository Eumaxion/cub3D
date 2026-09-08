/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:05:38 by mlima-si          #+#    #+#             */
/*   Updated: 2026/09/08 19:09:29 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	draw_minimap_tile(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			img_pixel_put(&g->screen,
				MINIMAP_MARGIN + x * MINIMAP_SCALE + j,
				MINIMAP_MARGIN + y * MINIMAP_SCALE + i,
				color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_row(t_game *g, int y)
{
	int		x;
	char	tile;

	x = 0;
	while (x < g->map_parse.width)
	{
		if ((size_t)x < strlen(g->map_parse.grid[y]))
			tile = g->map_parse.grid[y][x];
		else
			tile = -1;
		if (tile == '1')
			draw_minimap_tile(g, x, y, MAP_WALL_COLOR);
		else if (tile == '0' || ft_strchr("NSWE", tile))
			draw_minimap_tile(g, x, y, MAP_FLOOR_COLOR);
		x++;
	}
}

static void	draw_player_icon(t_game *g, int x, int y)
{
	int	px;
	int	py;
	int	color;

	py = 0;
	while (py < g->textures.player.height)
	{
		px = 0;
		while (px < g->textures.player.width)
		{
			color = get_tex_color(&g->textures.player, px, py);
			img_pixel_put(&g->screen,
				x - g->textures.player.width / 2 + px,
				y - g->textures.player.height / 2 + py,
				color);
			px++;
		}
		py++;
	}
}

static void	draw_minimap_player(t_game *g)
{
	int	x;
	int	y;

	x = MINIMAP_MARGIN + (int)(g->player.x * MINIMAP_SCALE);
	y = MINIMAP_MARGIN + (int)(g->player.y * MINIMAP_SCALE);
	draw_player_icon(g, x, y);
}

void	draw_minimap(t_game *g)
{
	int	y;

	y = 0;
	while (y < g->map_parse.height)
	{
		draw_minimap_row(g, y);
		y++;
	}
	draw_minimap_player(g);
}
