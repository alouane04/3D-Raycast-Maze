/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 08:43:30 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/29 16:37:21 by eel-moun         ###   ########.fr       */
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
	t_list *map;
} t_input;

#endif