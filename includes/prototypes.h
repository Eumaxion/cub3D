#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// -MAIN
int	main(int ac, char **av);

//-PARSING:
int	init_game(t_game *game);
int	parse_cub(char *av/* , t_game *game */);

//-ERROR: 
int	print_error(int error_code);

#endif