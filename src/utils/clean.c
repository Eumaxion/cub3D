# include "../includes/cub3D.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	clean_game(t_game *game)
{
	if (!game)
		return (1);
	if (game->map)
		free_matrix(game->map);
	if (game->map_parse.grid)
		free_matrix(game->map_parse.grid);
	return (1);
}
