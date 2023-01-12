#include "cub3D.h"

int check_wall(t_data *data, double x, double y)
{
    int i;
    int j;

    i = floor(x / TILE_SIZE);
    j = floor(y / TILE_SIZE);
    if(data->input->map[j][i] == '1' || data->input->map[j][i] == ' ' 
        || data->input->map[j][i] == '\0')
        return(0);
    return(1);
}

void get_next_pos(t_data *data, double *x, double *y,int dir)
{
    if(data->key->a || data->key->d)
    {
        *x += cos(data->player->rotationAgnles 
                + (dir * M_PI_2)) * data->player->walkSpeed;
        *y += sin(data->player->rotationAgnles 
                + (dir * M_PI_2)) * data->player->walkSpeed;
    }
    if(data->key->s || data->key->w)
    {
        *x += cos(data->player->rotationAgnles) 
                * dir * data->player->walkSpeed;;
        *y -= sin(data->player->rotationAgnles) 
                * dir * data->player->walkSpeed;;
    }
}
int handle_keyPress(int keynum, t_data *data)
{
    data->player->rotationAgnles = solve_angle(data->player->rotationAgnles);
    if(keynum == ESC_KEY)
    {
        mlx_destroy_image(data->mlx, data->image->img);
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    if(keynum == UP_M)
        data->key->w = 1;
    if(keynum == DOWN_M)
        data->key->s = 1;
    if(keynum == RIGHT_M)
        data->key->d = 1;
    if(keynum == LEFT_M)
        data->key->a = 1;
    if(keynum == RIGHT_R)
        data->key->right = 1;
    if(keynum == LEFT_R)
        data->key->left = 1;
    return (0);
}

int handle_keyrelease(int keynum, t_data *data)
{
    data->player->rotationAgnles = solve_angle(data->player->rotationAgnles);
    if(keynum == UP_M)
        data->key->w = 0;
    if(keynum == DOWN_M)
        data->key->s = 0;
    if(keynum == RIGHT_M)
        data->key->d = 0;
    if(keynum == LEFT_M)
        data->key->a = 0;
    if(keynum == RIGHT_R)
        data->key->right = 0;
    if(keynum == LEFT_R)
        data->key->left = 0;
    return (0);
}

int move_player(t_data *data)
{
    double nextx;
    double nexty;

    nextx = data->player->x;
    nexty = data->player->y;
    if(data->key->w)
        get_next_pos(data, &nextx, &nexty, 1);
    if(data->key->s)
        get_next_pos(data, &nextx, &nexty, -1);
    if(data->key->d)
        get_next_pos(data, &nextx, &nexty, 1);
    if(data->key->a)
        get_next_pos(data, &nextx, &nexty, -1);
    if(data->key->right)
        data->player->rotationAgnles += data->player->turnSpeed;
    if(data->key->left)
        data->player->rotationAgnles -= data->player->turnSpeed;
    if(check_wall(data, nextx, nexty))
    {
        data->player->x = nextx;
        data->player->y = nexty;
    }
    return(0);
}