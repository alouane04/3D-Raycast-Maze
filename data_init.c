#include "cub3D.h"

int	set_player(t_data *data, char c, int x, int y)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if(!data->player)
		return (1);
	data->player->x = x * TILE_SIZE + TILE_SIZE / 2;
	data->player->y = y * TILE_SIZE + TILE_SIZE / 2;
	data->player->height = 10;
	data->player->width = 10;
	data->player->turnDirection = 0;
	data->player->walkDirection = 0;
	data->player->walkSpeed = TILE_SIZE / 4;
	data->player->turnSpeed = 45 * (M_PI / 180);
	if (c == 'N')
		data->player->rotationAgnles = M_PI / 2;
	else if (c == 'W')
		data->player->rotationAgnles = M_PI;
	else if (c == 'S')
		data->player->rotationAgnles = 3 * (M_PI / 2);
	else if (c == 'E')
		data->player->rotationAgnles = 0;
	return (0);
}

int	setup(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->input->map[i])
	{
		while(data->input->map[i][j])
		{
			if(data->input->map[i][j] == 'N' || data->input->map[i][j] == 'S' 
				|| data->input->map[i][j] == 'E' || data->input->map[i][j] == 'W')
				{
					if (set_player(data, data->input->map[i][j], j, i))
						return (1);
					return (0);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	data_init(t_data *data, t_input *input)
{
	data->input = input;
	set_row_col(data);
	data->fov = 60 * (M_PI / 180);
	if (setup(data))
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!data->win)
		return (1);
	data->image = ft_calloc(1, sizeof(t_image));
	if (!data->image)
		return (1);
	data->image->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->image->img)
		return (1);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel
							, &data->image->line_length, &data->image->endian);
	return (0);
}