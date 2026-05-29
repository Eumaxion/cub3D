#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// init.c
void    init_game(t_game *g);
void    init_player(t_game *g);

// raycaster.c
void    render_frame(t_game *g);

// draw.c
void    img_pixel_put(t_img *img, int x, int y, int color);
void    draw_column(t_game *g, int x);

// main.c
int     key_hook(int keycode, void *param);
int     close_hook(void *param);
int     render_loop(void *param);
int     main(int ac, char **av);

#endif
