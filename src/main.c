/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:52:50 by mlima-si          #+#    #+#             */
/*   Updated: 2026/08/02 17:40:27 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	wait_for_input(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, (int (*)()) key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, (int (*)()) key_release, game);
	mlx_hook(game->win, 17, 0, (int (*)()) close_hook, game);
	if (BONUS)
		mlx_hook(game->win, MotionNotify, PointerMotionMask,
			mouse_handler, game);
}

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
	if (validate_xpms(&game))
		return (EXIT_FAILURE);
	init_textures(&game);
	game.map = game.map_parse.grid;
	render_frame(&game);
	wait_for_input(&game);
	mlx_loop_hook(game.mlx, (int (*)()) render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
