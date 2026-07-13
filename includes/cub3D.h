
#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
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

# define USAGE_ERR "USAGE: ./cub3d map.cub\n"
# define EXTENSION_ERR "Invalid file, EXAMPLE.cub required.\n"
# define XPM_ERROR "Invalid xpm\n"
# define IS_DIRECTORY "The file is a directory\n"
# define CUB_FILE 1
# define XPM_FILE 0

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif
# define WIN_W  800
# define WIN_H  600
# define MOV_SPEED   0.007
# define ROT_SPEED   0.006


#endif
