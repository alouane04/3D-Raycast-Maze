/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:05 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/13 19:21:25 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length + x
			* (data->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	handle_key_press(int keynum, t_data *data)
{
	data->player->rotation_agnles = solve_angle(data->player->rotation_agnles);
	if (keynum == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->image->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keynum == UP_M)
		data->key->w = 1;
	if (keynum == DOWN_M)
		data->key->s = 1;
	if (keynum == RIGHT_M)
		data->key->d = 1;
	if (keynum == LEFT_M)
		data->key->a = 1;
	if (keynum == RIGHT_R)
		data->key->right = 1;
	if (keynum == LEFT_R)
		data->key->left = 1;
	return (0);
}

int	handle_keyrelease(int keynum, t_data *data)
{
	data->player->rotation_agnles = solve_angle(data->player->rotation_agnles);
	if (keynum == UP_M)
		data->key->w = 0;
	if (keynum == DOWN_M)
		data->key->s = 0;
	if (keynum == RIGHT_M)
		data->key->d = 0;
	if (keynum == LEFT_M)
		data->key->a = 0;
	if (keynum == RIGHT_R)
		data->key->right = 0;
	if (keynum == LEFT_R)
		data->key->left = 0;
	return (0);
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
		{
			if (data->texture[i]->img)
			{
				mlx_destroy_image(data->mlx, data->texture[i]->img);
				free(data->texture[i]);
			}
		}
	}
	free_input(data->input);
}
