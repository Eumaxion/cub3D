#include "../includes/cub3D.h"

//loop principal: itera cada coluna do ecrã
void	render_frame(t_game *g)
{
	int	x = 0;
	while(x < WIN_W)
	{
	
	}
	//envia img para a janela
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
}
