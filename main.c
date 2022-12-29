/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:44:20 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/28 15:27:32 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"


t_list	*stock_input(int fd)
{
	t_list	*input;
	char	*str;

	input = NULL;
	while(1)
	{
		str =get_next_line(fd);
		if(*str == '\0')
			break;
		else if(!str)
			return(free(input), NULL);
		check_line();	
		ft_lstadd_back(&input, ft_lstnew(str));
		free(str);
	}
	return (free(str),input);
}

int	check_map_name(char *name)
{
	size_t	i;

	i = 0;
	while (name && i < (ft_strlen(name) - 4))
		name++;
	if (ft_strncmp(name, ".cub", 4))
		return (1);
	return (0);
}

int main(int ac, char **av)
{

	//t_input	*input;
	int		fd;
	
	if (ac != 2)
		return (ft_putendl_fd("Error invalid argument", 2), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error can't open map", 2), 1);
	if (check_map_name(av[1]))
		return (ft_putendl_fd("Error invalid map name", 2), 1);
	return (0);
}

