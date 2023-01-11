#include "cub3D.h"

int	set_player(t_data *data, char c, int x, int y)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if(!data->player)
		return (1);
	data->player->x = x * TILE_SIZE + TILE_SIZE / 2;
	data->player->y = y * TILE_SIZE + TILE_SIZE / 2;
	data->player->walkSpeed = TILE_SIZE / 4;
	data->player->turnSpeed = 15 * (M_PI / 180);
	if (c == 'N')
		data->player->rotationAgnles = M_PI / 2;
	if (c == 'W')
		data->player->rotationAgnles = M_PI;
	if (c == 'S')
		data->player->rotationAgnles = 3 * (M_PI / 2);
	if (c == 'E')
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

float solve_angle(float angle)
{
	angle  = remainder(angle , 2 * M_PI);
	if(angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}

void ray_init(t_ray *ray, float angle)
{
	/*if(angle > M_PI_2 && angle < M_PI)
		ray->ray_angle = M_PI - angle;
	else if(angle > (3 * M_PI_2))
		ray->ray_angle = (2 * M_PI) - angle;
	else*/
		ray->ray_angle = angle;
	if(angle > 0 && angle < M_PI)
		ray->is_ray_facing_up = 1;
	else
		ray->is_ray_facing_up = 0;
	if(angle < M_PI_2 || angle > (3 * M_PI_2))
		ray->is_ray_facing_right = 1;
	else
		ray->is_ray_facing_right = 0;
	ray->wall_hithx = 0;
	ray->wall_hithy = 0;
	ray->wall_hitvx = 0;
	ray->wall_hitvy = 0;
	ray->distance = 0;
	ray->was_hit_vertical = 0;
}

static void	texture_img_data_addr(t_data *data)
{
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	data->texture[0]->addr = mlx_get_data_addr(data->texture[0]->img, 
		&bits_per_pixel, &line_length, &endian);
	data->texture[1]->addr = mlx_get_data_addr(data->texture[1]->img,
		&bits_per_pixel, &line_length, &endian);
	data->texture[2]->addr = mlx_get_data_addr(data->texture[2]->img,
		&bits_per_pixel, &line_length, &endian);
	data->texture[3]->addr = mlx_get_data_addr(data->texture[3]->img,
		&bits_per_pixel, &line_length, &endian);
}

int	texture_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i] = ft_calloc(1, sizeof(t_texturs));
		if (!data->texture[i])
			return (1);
		i++;
	}
	data->texture[0]->img = mlx_xpm_file_to_image(data->mlx, data->input->no,
		&data->texture[0]->width, &data->texture[0]->height);
	data->texture[1]->img = mlx_xpm_file_to_image(data->mlx, data->input->no,
		&data->texture[1]->width, &data->texture[1]->height);
	data->texture[2]->img = mlx_xpm_file_to_image(data->mlx, data->input->no,
		&data->texture[2]->width, &data->texture[2]->height);
	data->texture[3]->img = mlx_xpm_file_to_image(data->mlx, data->input->no,
		&data->texture[3]->width, &data->texture[3]->height);
	if (!data->texture[0]->img || !data->texture[1]->img
		|| !data->texture[2]->img || !data->texture[3]->img)
		return (1);
	texture_img_data_addr(data);
	return (0);
}

int	data_init(t_data *data, t_input *input)
{
	data->input = input;
	set_row_col(data);
	data->ray = ft_calloc(1, sizeof(t_ray));
	if(!data->ray)
		return(1);
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
	if (texture_img(data))
		return (1);
	return (0);
}