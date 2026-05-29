#include "../includes/cub3D.h"

char    *g_map[] = {
    "111111111111",
    "100000000001",
    "100000000001",
    "100110000001",
    "100000000001",
    "100000110001",
    "100000000001",
    "100000000001",
    "111111111111",
    NULL
};

void	init_player(t_game *g)
{
	g->player.x      = 2.0;   // posição no mapa (coluna)
	g->player.y      = 2.0;   // posição no mapa (linha)
	g->player.dir_x  = 1.0;   // a olhar para Este
	g->player.dir_y  = 0.0;
	g->player.plane_x = 0.0;  // plano da câmara (perpendicular à dir)
	g->player.plane_y = 0.66; // 66% dá ~66° de FOV
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		write(2, "mlx_init() failed\n", 18);
		exit(1);
	}
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	if (!g->win)
	{
		write(2, "mlx_new_window() failed\n", 24);
		exit(1);
	}
	// cria imagem onde desenhamos (double buffer)
	g->screen.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->screen.addr = mlx_get_data_addr(g->screen.img,
                        &g->screen.bpp,
                        &g->screen.line_len,
                        &g->screen.endian);
	g->map = g_map;
	g->colors.ceiling = 0x1A1A2E;  // azul escuro
	g->colors.floor   = 0x4A3728;  // castanho
	init_player(g);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_column(t_game *g, int x)
{
	int	color;
	int	y;

	// N/S = vermelho, E/W = verde (mais escuro para dar profundidade)
	if (g->ray.side == 0)
		color = 0xFF0000;
	else
		color = 0x00AA00;

	// tecto (preto)
	y = 0;
	while (y < g->ray.draw_start)
	{
		img_pixel_put(&g->screen, x, y, g->colors.ceiling);
		y++;
	}
	// parede
	while (y <= g->ray.draw_end)
	{
		img_pixel_put(&g->screen, x, y, color);
		y++;
	}
	// chão (cinzento)
	while (y < WIN_H)
	{
		img_pixel_put(&g->screen, x, y, g->colors.floor);
		y++;
	}
}
