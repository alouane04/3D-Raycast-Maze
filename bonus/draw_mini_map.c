#include "../cub3D.h"

void	render_player(t_data *data, int x,int y,int color)
{
	int end_x = x + data->player->width;
	int end_y = y + data->player->height;

	while(x < end_x)
	{
		while(y < end_y)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = y - data->player->height;
		x++;
	}
}

void	draw_mini_map(t_data *data, int x, int y, int color)
{
	int temp_x = x + TILE_SIZE;
	int temp_y = y + TILE_SIZE;

	if(x < 0 || y < 0)
		return ;
	while(x < temp_x && x <= MINI_MAP_WIDTH)
	{
		while(y < temp_y && y <= MINI_MAP_HEIGHT)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = y - TILE_SIZE;
		x++;
	}
}

int	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->num_rows)
	{
		j = 0;
		while (j < data->num_cols)
		{
			if (data->input->map[i][j] == '1')
				draw_mini_map(data, (j * TILE_SIZE) - (data->player->x - 100)
                    , (i * TILE_SIZE) - (data->player->y - 100), 0x00ff0000);
			else if(data->input->map[i][j] == '0'|| data->input->map[i][j] == 'N' 
                    ||data->input->map[i][j] == 'S' || data->input->map[i][j] == 'E' 
                        || data->input->map[i][j] == 'W')
				draw_mini_map(data, (j * TILE_SIZE) - (data->player->x - 100)
                    , (i * TILE_SIZE) - (data->player->y - 100), 0x00ffffff);
			j++;
		}
		i++;
	}
    render_player(data, 97, 97, 0x0000ff00);
	return (0);
}