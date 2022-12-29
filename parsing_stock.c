#include "cube3D.h"

void	init_input(t_input	*input)
{
	input->no = NULL;
	input->so = NULL;
	input->ea = NULL;
	input->we = NULL;
	input->f = NULL;
	input->c = NULL;
	input->map = NULL;
}

int	*stock_rgb(char *str)
{
	int 	*i_rgb;
	char 	**c_rgb;
	int		i;

	i = 0;
	c_rgb = check_rgb(str);
	if(!c_rgb)
		return (NULL);
	i_rgb = malloc(sizeof(int) * 3);
	if(!i_rgb)
		return (ft_free(c_rgb), NULL);
	while(c_rgb[i])
	{
		i_rgb[i] = ft_atoi(c_rgb[i]);
		if(i_rgb[i]< 0 || i_rgb[i] > 255)
			return(ft_free(c_rgb), free(i_rgb), NULL);
		i++;
	}
	return (ft_free(c_rgb), i_rgb);
}

int	check_if_empty(t_input *input)
{
	if (!input->no)
		return (1);
	if (!input->so)
		return (1);
	if (!input->ea)
		return (1);
	if (!input->we)
		return (1);
	if (!input->f)
		return (1);
	if (!input->c)
		return (1);
	return (0);
}

int	stock_input(int fd, t_input *input)
{
	char	*str;

	while(1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (check_line(str, input))
			return (free(str), ft_putendl_fd("Error invalid map", 2), 1);
		free(str);
	}
	if (check_if_empty(input))
		return (free(str), ft_putendl_fd("Error invalid map1", 2), 1);
	return (free(str), 0);
}
