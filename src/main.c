#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return(print_error(USAGE_ERR, NULL, 0));
	init_game(&game);
	if (parse_cub(av[1], &game))
		return (clean_game(&game));
	//run_game(&game);
	return (EXIT_SUCCESS);
}

/* int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	fd = open("src/text.txt", O_RDONLY);
	if (fd <= 0)
		return (print_error(strerror(errno), NULL, 0));
	char *line;
	line = get_next_line(fd);
	while(line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return 0;
} */