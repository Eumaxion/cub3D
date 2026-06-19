#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// -MAIN
int	main(int ac, char **av);

//-PARSING:
int	init_game(t_game *game);
int	file_test(char *file, int type);
int	parse_cub(char *av, t_game *game);

//-ERROR && CLEANING: 
int	print_error(char *arg, t_game *game, int clean);
int	clean_game(t_game *game);

#endif