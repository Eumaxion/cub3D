#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// move.c
void    move_forward_back(t_game *g, int dir);
void    move_strafe(t_game *g, int dir);
void    rotate(t_game *g, int dir);

// init.c
void    init_game(t_game *g);
void    init_player(t_game *g);
void    init_textures(t_game *g);

// raycaster.c
void    render_frame(t_game *g);

// draw.c
void    img_pixel_put(t_img *img, int x, int y, int color);
void    draw_column(t_game *g, int x);

// main.c
int     key_press(int keycode, void *param);
int     key_release(int keycode, void *param);
int     close_hook(void *param);
int     render_loop(void *param);
int     main(int ac, char **av);

#endif
