// #include <mlx.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	printf("%d\n",keycode);
// 	// mlx_destroy_window(vars->mlx, vars->win);
// 	// return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	//mlx_hook(vars.win, 17, 0, close, &vars);
// 		mlx_key_hook(vars.win, close, &vars);
// 	mlx_loop(vars.mlx);
// }


// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <mlx.h>

// // // #include <X11/X.h>
// // // #include <X11/keysym.h>

// // #define WINDOW_WIDTH 600
// // #define WINDOW_HEIGHT 300

// // #define MLX_ERROR 1

// // typedef struct s_data
// // {
// // 	void	*mlx_ptr;
// // 	void	*win_ptr;
// // }	t_data;

// // int	handle_no_event(void *data)
// // {
// // 	/* This function needs to exist, but it is useless for the moment */
// // 	return (0);
// // }

// // int	handle_keypress(int keysym, t_data *data)
// // {
// // 	if (keysym == 53)
// // 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);

// // 	printf("Keypress: %d\n", keysym);
// // 	return (0);
// // }

// // int	handle_keyrelease(int keysym, void *data)
// // {
// // 	printf("Keyrelease: %d\n", keysym);
// // 	return (0);
// // }

// // int	main(void)
// // {
// // 	t_data	data;

// // 	data.mlx_ptr = mlx_init();
// // 	if (data.mlx_ptr == NULL)
// // 		return (MLX_ERROR);
// // 	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
// // 	if (data.win_ptr == NULL)
// // 	{
// // 		free(data.win_ptr);
// // 		return (MLX_ERROR);
// // 	}

// // 	/* Setup hooks */ 
// // 	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
// // 	mlx_hook(data.win_ptr, 17, KeyPressMask, &handle_keypress, &data); /* ADDED */
// // 	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */

// // 	mlx_loop(data.mlx_ptr);

// // 	/* we will exit the loop if there's no window left, and execute this code */
// // 	mlx_destroy_display(data.mlx_ptr);
// // 	free(data.mlx_ptr);
// // }
#include <stdio.h>

int main()
{
	int	r = 1 ? 0 : 1;
	printf("%d\n", r);
}
