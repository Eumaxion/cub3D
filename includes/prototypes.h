#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// -MAIN
int		main(int ac, char **av);

//-PARSING:
void	init_game(t_game *game);
void	init_map(t_map *map_parse);
int		file_test(char *file, int type);
int		parse_cub(char *av, t_game *game);
int		read_file(char *path);
int		parse_textures(t_game *game, int fd);
void	free_matrix(char **matrix);

//-ERROR && CLEANING: 
int		print_error(char *arg, t_game *game, int clean);
int		clean_game(t_game *game);

#endif