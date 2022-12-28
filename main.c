/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:44:20 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/28 11:24:45 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	check_error(t_input *input)
{
	int	i;
	
	i = 0;
	
}

int main(int ac, char **av)
{
    t_input	input;

	if (ac != 2)
		return (ft_putendl_fd("Error", 2), 1);
    int fd = open(av[1], O_RDWR);
	if (!fd)
		return (fd_putendl_fd("Error can't open map", 2), 1);
	if (ft_strsep(&av[1], ))
	if (check_error(&input))
		return (1);

	return (0);
}
