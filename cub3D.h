/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 08:43:30 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/05 08:59:36 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <errno.h>
# include <mlx.h>
#include <math.h>

# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define NUM_RAYS WINDOW_HEIGHT
#define TILE_SIZE 64

typedef struct s_input
{
    char	*no;
    char	*so;
    char	*ea;
	char	*we;
	int		*f;
	int		*c;
	char 	**map;
} 			t_input;

typedef struct s_player
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		turnDirection; // -1 for left, +1 for right
	int		walkDirection;// -1 for back, +1 for right
	float	rotationAgnles;
	float	walkSpeed;
	float	turnSpeed;
}			t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			num_rows;
	int			num_cols;
	int			fov;
	t_input		*input;
	t_player	*player;
	t_image		*image;
}			t_data;

int		*stock_rgb(char *str);
void	init_input(t_input	*input);
char	**check_rgb(char *str);
int		check_map_name(char *name);
int 	check_texture(char *str, t_input *input);
int		check_line(char *str, t_input *input, int fd);
int		stock_input(int fd, t_input *input);
char	*stock_line(char const *s, int len);
int 	check_color(char *str, t_input *input);
void	free_input(t_input *input);
t_list	*stock_lst(int fd, char *str, t_list *lst);
int		check_map(char *str, t_input *input, int fd);
int		check_if_empty(t_input *input);
void	stock_map(t_list *lst, t_input *input);
int		get_biggest_line(t_list *lst);
void	set_row_col(t_data *data);

#endif