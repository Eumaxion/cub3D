/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:53:11 by mlima-si          #+#    #+#             */
/*   Updated: 2026/09/08 11:48:42 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libs/libft/libft.h"
# include "structs.h"
# include "prototypes.h"

// MACROS

# define USAGE_ERR "USAGE: ./cub3d map.cub.\n"
# define EXTENSION_ERR "Invalid file, EXAMPLE.cub required.\n"
# define XPM_ERROR "Invalid xpm.\n"
# define IS_DIRECTORY "The file is a directory.\n"
# define MAP_UNCLOSED "Map is not closed.\n"
# define DUP_COLOR "Duplicated cealing/floor.\n"
# define DUP_TXT "Duplicated texture.\n"
# define DUP_PATH "Duplicated path.\n"
# define PLAYER_N "Invalid player number.\n"
# define MAP_CHAR "Invalid map character.\n"
# define MLX_ERR "mlx_init failed.\n"
# define MLX_FAIL "mlx_new_window failed.\n"
# define INVALID_RGB "Invalid RGB.\n"
# define SAME_COLOR "Floor and ceiling colors cannot be equal.\n"

# define CUB_FILE 1
# define XPM_FILE 0

# ifndef BONUS
#  define BONUS 1
# endif

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define WIN_W 1280
# define WIN_H 720
# define MOUSE_SENSITIVITY 0.0050
# define MOV_SPEED 0.020
# define ROT_SPEED 0.020

# define MINIMAP_SCALE 12
# define MINIMAP_MARGIN 20

# define MAP_WALL_COLOR 0x5C3A2E
# define MAP_FLOOR_COLOR 0x1E1A17

#endif
