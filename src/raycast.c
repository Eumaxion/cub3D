#include "../includes/cub3D.h"

//inicializa direcção e posição do raio para a coluna x
static void	init_ray(t_game *g, int x)
{
	t_ray    *r = &g->ray;
	t_player *p = &g->player;

	// camera_x: -1 (esquerda) a +1 (direita) do ecrã
	r->camera_x  = 2.0 * x / WIN_W - 1.0;
	r->raydir_x  = p->dir_x + p->plane_x * r->camera_x;
	r->raydir_y  = p->dir_y + p->plane_y * r->camera_x;

	// célula do mapa onde o jogador está
	r->map_x = (int)p->x;
	r->map_y = (int)p->y;

    // deltadist: distância entre duas paredes consecutivas X ou Y
    // evita divisão por zero com 1e30
	if (r->raydir_x == 0)
		r->deltadist_x = 1e30;
	else
		r->deltadist_x = fabs(1.0 / r->raydir_x);
	if (r->raydir_y == 0)
		r->deltadist_y = 1e30;
	else
		r->deltadist_y = fabs(1.0 / r->raydir_y);
}

//loop principal: itera cada coluna do ecrã
void	render_frame(t_game *g)
{
	int	x = 0;
	while(x < WIN_W)
	{
		init_ray(g, x);
	}
	//envia img para a janela
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
}
