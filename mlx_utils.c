#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length + x * (data->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
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
	while (++i < 4)
	{
		if (data->texture[i])
			if (data->texture[i]->img)
			{
				mlx_destroy_image(data->mlx, data->texture[i]->img);
				free(data->texture[i]);
			}
	}
	free_input(data->input);
}
