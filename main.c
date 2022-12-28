
#include "cube3D.h"

// int	check_error(t_input *input)
// {
// 	int	i;
	
// 	i = 0;
	
// }

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
