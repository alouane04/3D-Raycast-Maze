
#include "cub3D.h"

// void	leaks()
// {
// 	system ("leaks cub3D");
// }k
int	start_game(t_data *data)
{
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
	return 0;
}



int main(int ac, char **av)
{
	// atexit(leaks);
	t_input	input;
	t_data	data;
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
	if (data_init(&data, &input))
		return (free_data(&data), 1);
	mlx_loop_hook(data.mlx, start_game, &data);
	mlx_hook(data.win, 02, 1L<<0, &handle_keyPress, &data);
	mlx_hook(data.win, 03, 1L<<1, &handle_keyrelease, &data);
	mlx_loop(data.mlx);
		printf("tesflgd\n");
	return (free_data(&data), 0);
}
