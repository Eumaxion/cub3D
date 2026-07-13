#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// -MAIN
int		main(int ac, char **av);

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
int	validate_map(t_game *game);
int	check_chars(t_game *game);
int	check_player(t_game *game);
int	check_closed(t_game *game);
// move.c
void    move_forward_back(t_game *g, int dir);
void    move_strafe(t_game *g, int dir);
void    rotate(t_game *g, int dir);

// init.c
void    init_game(t_game *g);
void    init_player(t_game *g);
void    init_textures(t_game *g);

// raycaster.c
void    render_frame(t_game *g);

// draw.c
void    img_pixel_put(t_img *img, int x, int y, int color);
void    draw_column(t_game *g, int x);

// main.c
int     key_press(int keycode, void *param);
int     key_release(int keycode, void *param);
int     close_hook(void *param);
int     render_loop(void *param);
int     main(int ac, char **av);

#endif
