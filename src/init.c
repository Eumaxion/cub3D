#include "../includes/cub3D.h"

char    *g_map[] = {
    "111111111111",
    "1000000000011111111",
    "1000000000000000001",
    "1001100000011111111",
    "100000000001",
    "100000110001",
    "100000000001",
    "100000000001",
    "111111111111",
    NULL
};

void    init_textures(t_game *g)
{
    g->tex.north.img = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &g->tex.w, &g->tex.h);
    g->tex.south.img = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &g->tex.w, &g->tex.h);
    g->tex.west.img  = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm",  &g->tex.w, &g->tex.h);
    g->tex.east.img  = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm",  &g->tex.w, &g->tex.h);
    g->tex.north.addr = mlx_get_data_addr(g->tex.north.img, &g->tex.north.bpp, &g->tex.north.line_len, &g->tex.north.endian);
    g->tex.south.addr = mlx_get_data_addr(g->tex.south.img, &g->tex.south.bpp, &g->tex.south.line_len, &g->tex.south.endian);
    g->tex.west.addr  = mlx_get_data_addr(g->tex.west.img,  &g->tex.west.bpp,  &g->tex.west.line_len,  &g->tex.west.endian);
    g->tex.east.addr  = mlx_get_data_addr(g->tex.east.img,  &g->tex.east.bpp,  &g->tex.east.line_len,  &g->tex.east.endian);
}

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
	init_textures(g);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int  get_tex_color(t_img *tex, int tex_x, int tex_y)
{
    char    *dst;

    dst = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
    return (*(unsigned int *)dst);
}

static t_img    *get_wall_texture(t_game *g)
{
    t_ray   *r = &g->ray;

    if (r->side == 0)
    {
        if (r->raydir_x > 0)
            return (&g->tex.east);
        return (&g->tex.west);
    }
    if (r->raydir_y > 0)
        return (&g->tex.south);
    return (&g->tex.north);
}

void    draw_column(t_game *g, int x)
{
    t_ray   *r = &g->ray;
    t_img   *tex;
    double  step;
    double  tex_pos;
    int     tex_y;
    int     color;
    int     y;

    tex = get_wall_texture(g);
    // quanto a textura avança por pixel de ecrã
    step = 1.0 * g->tex.h / r->line_height;
    // posição inicial na textura
    tex_pos = (r->draw_start - WIN_H / 2 + r->line_height / 2) * step;

    y = 0;
    while (y < r->draw_start)
    {
        img_pixel_put(&g->screen, x, y, g->colors.ceiling);
        y++;
    }
    while (y <= r->draw_end)
    {
        tex_y = (int)tex_pos & (g->tex.h - 1);
        tex_pos += step;
        color = get_tex_color(tex, r->tex_x, tex_y);
        img_pixel_put(&g->screen, x, y, color);
        y++;
    }
    while (y < WIN_H)
    {
        img_pixel_put(&g->screen, x, y, g->colors.floor);
        y++;
    }
}

/*void	draw_column(t_game *g, int x)
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
}*/
