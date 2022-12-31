
#include "cube3D.h"

int main(int ac, char **av)
{
	t_input	input;
	//int		fd;
	(void)ac;

	//if (ac != 2)
	//	return (ft_putendl_fd("Error invalid argument", 2), 1);
	//fd = open(av[1], O_RDONLY);
	//if (fd == -1)
	//	return (ft_putendl_fd("Error can't open map", 2), 1);
	//if (check_map_name(av[1]))
	//	return (ft_putendl_fd("Error invalid map name", 2), 1);
	init_input(&input);
	av++;
	if (stock_input(av, &input))
		return(free_input(&input), 1);
	//("%d\n", input.c[0]);
	return (0);
}
