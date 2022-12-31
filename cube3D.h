/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 08:43:30 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/31 09:04:17 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <errno.h>

typedef struct s_input{
    char	*no;
    char	*so;
    char	*ea;
	char	*we;
	int		*f;
	int		*c;
	char 	**map;
} t_input;

int		*stock_rgb(char *str);
void	init_input(t_input	*input);
char	**check_rgb(char *str);
int		check_map_name(char *name);
int 	check_texture(char *str, t_input *input);
int		check_line(char *str, t_input *input);
int		stock_input(char **av, t_input *input);
int 	check_color(char *str, t_input *input);
void	free_input(t_input *input);
void	stock_lst(char **av, char *str, t_list *lst);
int		check_if_map(char **av, char *str, t_list *lst);
int		check_if_empty(t_input *input);
void	stock_map(t_list *lst, t_input *input);

#endif