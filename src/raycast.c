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

//DDA: avança célula a célula até bater numa parede
static void     dda(t_game *g)
{
        t_ray *r = &g->ray;

        r->hit = 0;
        while (!r->hit)
        {
                if (r->sidedist_x < r->sidedist_y)
                {
                        r->sidedist_x += r->deltadist_x;
                        r->map_x += r->step_x;
                        r->side = 0; // parede N ou S
                }
                else
                {
                        r->sidedist_y += r->deltadist_y;
                        r->map_y += r->step_y;
                        r->side = 1; // parede E ou W
                }
                if (g->map[r->map_y][r->map_x] == '1')
                        r->hit = 1;
        }
}

//calcula sidedist inicial e step
static void	calc_step_sidedist(t_game *g)
{
	t_ray    *r = &g->ray;
	t_player *p = &g->player;

	if (r->raydir_x < 0)
	{
		r->step_x     = -1;
		r->sidedist_x = (p->x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x     = 1;
		r->sidedist_x = (r->map_x + 1.0 - p->x) * r->deltadist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y     = -1;
		r->sidedist_y = (p->y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y     = 1;
		r->sidedist_y = (r->map_y + 1.0 - p->y) * r->deltadist_y;
	}
}

//calcula altura da coluna a desenhar
static void	calc_wall_height(t_game *g)
{
	t_ray    *r = &g->ray;

	// distância perpendicular (evita fish-eye)
	if (r->side == 0)
		r->perpwalldist = r->sidedist_x - r->deltadist_x;
	else
		r->perpwalldist = r->sidedist_y - r->deltadist_y;
	r->line_height = (int)(WIN_H / r->perpwalldist);
	r->draw_start = WIN_H / 2 - r->line_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = WIN_H / 2 + r->line_height / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
}

//loop principal: itera cada coluna do ecrã
void	render_frame(t_game *g)
{
	int	x = 0;
	while(x < WIN_W)
	{
		init_ray(g, x);
		calc_step_sidedist(g);
		dda(g);
		calc_wall_height(g);
		draw_column(g, x);
		x++;
	}
	//envia img para a janela
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
}
