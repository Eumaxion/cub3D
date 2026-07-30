/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:53:57 by mlima-si          #+#    #+#             */
/*   Updated: 2026/07/30 16:44:51 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map		t_map;
typedef struct s_game		t_game;
typedef struct s_img		t_img;
typedef struct s_texture	t_texture;
typedef struct s_player		t_player;
typedef struct s_colors		t_colors;
typedef struct s_ray		t_ray;

typedef struct s_map
{
	char	**grid;
	int		map_index;
	int		width;
	int		height;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	int		w;
	int		h;
}	t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	angle;
	int		moved;
}	t_player;

typedef struct s_colors
{
	int	floor;
	int	ceiling;
	int	floor_set;
	int	ceiling_set;
}	t_colors;

typedef struct s_draw
{
	t_ray	*r;
	t_img	*tex;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	int		y;
}	t_draw;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		textures_x;
	int		special;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*map_path;
	int			ignore_mouse;
	t_map		map_parse;
	t_player	player;
	t_ray		ray;
	t_img		screen;
	t_texture	textures;
	t_colors	colors;
	int			keys[65536];
}	t_game;

#endif
