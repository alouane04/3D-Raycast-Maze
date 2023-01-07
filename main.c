
#include "cub3D.h"

// void	leaks()
// {
// 	system ("leaks cub3D");
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int temp = x + (3 *  TILE_SIZE);
	int temp2 = y + (3 *  TILE_SIZE);
	char	*dst;

	printf("%d..%d\n",temp, temp2);
	// while(x < temp)
	// {
	// 	while(y < temp2)
	// 	{
	// 		dst = data->image->addr + (y * data->image->line_length + x * (data->image->bits_per_pixel / 8));
	// 		*(unsigned int*)dst = color;
	// 		y++;
	// 	}
	// 	y = y - TILE_SIZE;
	// 	x++;
	// }
	while(x < temp)
	{
		dst = data->image->addr + (0 * data->image->line_length + x * (data->image->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		x++;
	}
	while(y < temp2)
	{
		dst = data->image->addr + (y * data->image->line_length + 0 * (data->image->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		y++;
	}
}

int	set_player(t_data *data, char c, int x, int y)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if(!data->player)
		return (1);
	data->player->x = x * TILE_SIZE + TILE_SIZE / 2;
	data->player->y = y * TILE_SIZE + TILE_SIZE / 2;
	data->player->height = 5;
	data->player->width = 5;
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
					if (set_player(data, data->input->map[i][j], i, j))
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

int	render_map(t_data *data)
{
	int	i;
	int	j;
	int	tile_x;
	int	tile_y;
	int	tile_color;

	i = 0;
	while (i < data->num_rows)
	{
		j = 0;
		while (j < data->num_cols)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			if (data->input->map[i][j] == '1')
				tile_color = 0x00ffffff;
			else
				tile_color = 0x00ff0000;
			// printf("%d\n", tile_color);
			my_mlx_pixel_put(data, 0, 0, tile_color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return (0);
}

int	start_game(t_data *data)
{
	render_map(data);
	return 0;
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
	data->image->img = mlx_new_image(data->mlx, 100, 200);
	printf("test\n");
	if (!data->image->img)
		return (1);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel
							, &data->image->line_length, &data->image->endian);
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

int handle_keyPress(int keynum, t_data *data)
{
	if (keynum == ESC_KEY)
		mlx_destroy_window(data->mlx, data->win);
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

int main(int ac, char **av)
{
	//atexit(leaks);
	t_input	input;
	t_data	data;
	int		fd;

	if (ac != 2)
		return (ft_putendl_fd("Error invalid argument", 2), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error can't open map", 2), 1);
	if (check_map_name(av[1]))
		return (ft_putendl_fd("Error invalid map name", 2), 1);
	init_input(&input);
	if (stock_input(fd, &input))
		return(free_input(&input), 1);
	if (data_init(&data, &input))
		return (free_data(&data), 1);
	mlx_loop_hook(data.mlx, start_game, &data);
	mlx_hook(data.win, 02, 1L<<0, &handle_keyPress, &data);
	mlx_hook(data.win, 03, 1L<<1, &handle_keyrelease, &data);
	mlx_loop(data.mlx);
	return (free_data(&data), 0);
}
