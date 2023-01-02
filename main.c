
#include "cube3D.h"

// void	leaks()
// {
// 	system ("leaks cub3D");
// }

int main(int ac, char **av)
{
	//atexit(leaks);
	t_input	input;
	int		fd;

	if (ac != 2)
		return (ft_putendl_fd("Error invalid argument", 2), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error can't open map", 2), 1);
	if (check_map_name(av[1]))
		return (ft_putendl_fd("Error invalid map name", 2), 1);
	init_input(&input);
	if (stock_input(fd, &input))
		return(free_input(&input), 1);
	printf("%s\n", input.map[6]);
	return (free_input(&input), (0));
}
