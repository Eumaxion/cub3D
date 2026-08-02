/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:55:56 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/30 16:46:12 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

//-PARSING:
void	init_game(t_game *game);
void	init_map(t_map *map_parse);
int		parse_cub(char *av, t_game *game);
int		file_test(char *file, int type);
char	**read_file(char *path);
int		skip_spaces(char *line);
int		is_empty_line(char *line);
int		parse_elements(t_game *game, char **file);
int		is_texture(char *line);
int		parse_texture(t_game *game, char *line);
int		is_color(char *line);
int		parse_color(t_game *game, char *line);
int		parse_map(t_game *game, char **file);
void	free_matrix(char **matrix);

//-ERROR && CLEANING: 
int		print_error(char *arg, t_game *game, int clean);
int		clean_game(t_game *game);

//-MAP VALIDATION
int		validate_map(t_game *game);
int		check_chars(t_game *game);
int		check_player(t_game *game);
int		check_closed(t_game *game);
int		is_wall(char **map, int x, int y);
void	set_dir(t_game *game, char c);
int		is_player(char c);

// move.c
void	move_forward_back(t_game *g, int dir);
void	move_strafe(t_game *g, int dir);
void	rotate(t_game *g, double angle);

// raycaster.c
void	render_frame(t_game *g);
int		init_mlx(t_game *g);
void	init_textures(t_game *g);
void	init_ray(t_game *g, int x);

// draw.c
void	img_pixel_put(t_img *img, int x, int y, int color);
void	draw_column(t_game *g, int x);

// main.c
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
int		close_hook(void *param);
int		render_loop(void *param);
int		main(int ac, char **av);

// bonus
int	mouse_handler(int x, int y, t_game *game);

#endif
