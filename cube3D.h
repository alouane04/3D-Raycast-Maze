/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 08:43:30 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/28 19:02:05 by ariahi           ###   ########.fr       */
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

typedef struct s_input{
    char	*no;
    char	*so;
    char	*ea;
	char	*we;
	char	*f;
	char	*c;
	t_list *map;
} t_input;

#endif