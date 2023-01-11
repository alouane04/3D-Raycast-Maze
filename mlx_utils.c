#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length + x * (data->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void move_player(t_data *data,double rot_angle, int dir)
{
	int nextx;
    int nexty;
	int next2x;
    int next2y;

	nextx = ((data->player->x - 3 ) + cos(rot_angle) * (data->player->walkSpeed) * dir) / TILE_SIZE;
	nexty = ((data->player->y - 3) - sin(rot_angle) * (data->player->walkSpeed) * dir) / TILE_SIZE;
	next2x = ((data->player->x + 3 ) + cos(rot_angle) * (data->player->walkSpeed) * dir) / TILE_SIZE;
	next2y = ((data->player->y + 3) - sin(rot_angle) * (data->player->walkSpeed) * dir) / TILE_SIZE;
    if(data->input->map[nexty][nextx] != '1' && data->input->map[next2y][next2x] != '1' 
			&& data->input->map[nexty][next2x] != '1' && data->input->map[next2y][nextx] != '1')
    {
        data->player->x = data->player->x + cos(rot_angle) * data->player->walkSpeed * dir;
        data->player->y = data->player->y - sin(rot_angle) * data->player->walkSpeed * dir;
    }
}

int handle_keyPress(int keynum, t_data *data)
{
	if (keynum == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->image->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
    if (keynum == RIGHT_R)
        data->player->rotationAgnles = fmod((data->player->rotationAgnles + (2 * M_PI)
                                        - data->player->turnSpeed) ,(2 * M_PI)) ;
    if (keynum == LEFT_R)
        data->player->rotationAgnles = fmod((data->player->rotationAgnles
                                        + data->player->turnSpeed) ,(2 * M_PI)) ;
    if (keynum == UP_M)
		move_player(data, fmod((data->player->rotationAgnles) ,(2 * M_PI)), 1);
	if (keynum == DOWN_M)
		move_player(data, fmod((data->player->rotationAgnles) ,(2 * M_PI)), -1);
	if (keynum == LEFT_M)
		move_player(data, fmod((data->player->rotationAgnles + M_PI_2) ,(2 * M_PI)), 1);
	if (keynum == RIGHT_M)
		move_player(data, fmod((data->player->rotationAgnles - M_PI_2) ,(2 * M_PI)), 1);
	return(0);
}

void	free_data(t_data *data)
{
	if (data->image->img)
		mlx_destroy_image(data->mlx, data->image->img);
	if (data->image)
		free(data->image);
	if (data->win)
		mlx_destroy_window(data->win, data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (data->player)
		free(data->player);
	free_input(data->input);
}
