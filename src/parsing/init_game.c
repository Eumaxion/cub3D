/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:13:22 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/23 20:13:26 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_player(t_player *player)
{
	player->angle = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->x = 0.0;
	player->y = 0.0;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->raydir_x = 0.0;
	ray->raydir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
	ray->deltadist_x = 0.0;
	ray->deltadist_y = 0.0;
	ray->perpwalldist = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_img_colors(t_colors *colors)
{
	colors->ceiling = -1;
	colors->floor = -1;
}

void	init_img(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->path = NULL;
	image->bpp = 0;
	image->endian = 0;
	image->line_len = 0;
}

void	init_game(t_game *game)
{
	game->map = NULL;
	game->win = NULL;
	game->map_path = NULL;
	init_player(&game->player);
	init_map(&game->map_parse);
	init_ray(&game->ray);
	init_img(&game->screen);
	init_img(&game->textures.east);
	init_img(&game->textures.north);
	init_img(&game->textures.south);
	init_img(&game->textures.west);
	init_img_colors(&game->colors);
	ft_bzero(game->keys, sizeof(game->keys));
}
