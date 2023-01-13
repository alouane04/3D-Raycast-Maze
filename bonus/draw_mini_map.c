/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:57:11 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/13 19:04:22 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	render_player(t_data *data, int x, int y, int color)
{
	int	end_x;
	int	end_y;

	end_x = x + 6;
	end_y = y + 6;
	while (x < end_x)
	{
		while (y < end_y)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = y - 6;
		x++;
	}
}

void	draw_mini_map(t_data *data, int x, int y, int color)
{
	int	temp_x;
	int	temp_y;
	int	initialy;

	temp_x = x + TILE_SIZE;
	temp_y = y + TILE_SIZE;
	initialy = y;
	if (x < 0 || y < 0)
		return ;
	while (x < temp_x && x <= MINI_MAP_WIDTH)
	{
		while (y < temp_y && y <= MINI_MAP_HEIGHT)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = initialy;
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
				draw_mini_map(data, (j * TILE_SIZE) - (data->player->x - 100),
					(i * TILE_SIZE) - (data->player->y - 100), 0x00ff0000);
			else if (data->input->map[i][j] == '0'
						|| data->input->map[i][j] == 'N'
							|| data->input->map[i][j] == 'S'
								|| data->input->map[i][j] == 'E'
									|| data->input->map[i][j] == 'W')
				draw_mini_map(data, (j * TILE_SIZE) - (data->player->x - 100),
					(i * TILE_SIZE) - (data->player->y - 100), 0x00ffffff);
			j++;
		}
		i++;
	}
	render_player(data, 97, 97, 0x0000ff00);
	return (0);
}

void	render_back_ground(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j <= (WINDOW_HEIGHT / 2))
		{
			my_mlx_pixel_put(data, i, j,
				create_rgb(data->input->c[0],
					data->input->c[1],
					data->input->c[2]));
			j++;
		}
		while (j < WINDOW_HEIGHT)
		{
			my_mlx_pixel_put(data, i, j,
				create_rgb(data->input->f[0],
					data->input->f[1],
					data->input->f[2]));
			j++;
		}
		i++;
	}
}
