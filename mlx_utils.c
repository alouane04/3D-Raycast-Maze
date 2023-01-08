#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length + x * (data->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int handle_keyPress(int keynum, t_data *data)
{
	if (keynum == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->image->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if(keynum == UP_M)
		data->player->walkDirection = 1;
	else if(keynum == DOWN_M)
		data->player->walkDirection = -1;
	else if(keynum == LEFT_R)
		data->player->turnDirection = -1;
	else if(keynum == RIGHT_R)
		data->player->turnDirection = 1;
	return(0);
}

int handle_keyrelease(int keynum, t_data *data)
{
	if(keynum == UP_M)
		data->player->walkDirection = 0;
	else if(keynum == DOWN_M)
		data->player->walkDirection = 0;
	else if(keynum == LEFT_R)
		data->player->turnDirection = 0;
	else if(keynum == RIGHT_R)
		data->player->turnDirection = 0;
	return (0);
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
