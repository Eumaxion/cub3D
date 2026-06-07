# include "../includes/cub3D.h"


void	init_player(t_player *player)
{
	player->angle = 0.0;
	player->dir_x = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->x = 0.0;
	player->y = 0.0;
}

void	init_ray(t_ray *ray)
{}

void	init_img_colors(t_img *img, t_colors *colors)
{}

void	init_text(t_texture *texture)
{}

int	init_game(t_game *game)
{
	game->map = NULL;
	game->win = NULL;
	init_player(&game->player);
	init_ray(&game->ray);
	init_img_colors(&game->screen, &game->colors);
	init_text(&game->textures);
}