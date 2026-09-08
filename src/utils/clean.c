/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:34:15 by mlima-si          #+#    #+#             */
/*   Updated: 2026/09/08 12:29:41 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	check_textures(t_game *game)
{
	game->map = NULL;
	if (game->textures.north.path)
		free(game->textures.north.path);
	if (game->textures.south.path)
		free(game->textures.south.path);
	if (game->textures.west.path)
		free(game->textures.west.path);
	if (game->textures.east.path)
		free(game->textures.east.path);
}

int	clean_game(t_game *game)
{
	if (!game)
		return (1);
	if (game->map_parse.grid)
		free_matrix(game->map_parse.grid);
	check_textures(game);
	if (game->textures.north.img)
		mlx_destroy_image(game->mlx, game->textures.north.img);
	if (game->textures.south.img)
		mlx_destroy_image(game->mlx, game->textures.south.img);
	if (game->textures.west.img)
		mlx_destroy_image(game->mlx, game->textures.west.img);
	if (game->textures.east.img)
		mlx_destroy_image(game->mlx, game->textures.east.img);
	if (game->textures.player.img)
		mlx_destroy_image(game->mlx, game->textures.player.img);
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (1);
}
