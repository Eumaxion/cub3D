/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:52:50 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/25 16:58:43 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_error(USAGE_ERR, NULL, 0));
	init_game(&game);
	if (parse_cub(av[1], &game))
		return (clean_game(&game));
	if (init_mlx(&game))
		return (clean_game(&game));
	init_textures(&game);
	game.map = game.map_parse.grid;
	mlx_hook(game.win, 2, 1L << 0, (int (*)()) key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, (int (*)()) key_release, &game);
	mlx_hook(game.win, 17, 0, (int (*)()) close_hook, &game);
	mlx_loop_hook(game.mlx, (int (*)()) render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
