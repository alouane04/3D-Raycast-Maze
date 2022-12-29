
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

// void	skip_spaces(char **str)
// {
// 	int i;

// 	i = 0;
// 	while (*str[i])
// 	{
// 		if (ft_strchr(**str, ' '))
// 			*str++;
// 		i++;
// 	}
// }

int check_texture(char *str, t_input *input)
{
	char	c;

	c = *str;
	if (c == 'F' || c == 'C')
		str++;
	else
		str += 2;
	while (*str == ' ')
		str++;
	if (c == 'N' && !input->no)
		input->no = ft_strdup(str);
	else if (c == 'S' && !input->so)
		input->so = ft_strdup(str);
	else if (c == 'W' && !input->we)
		input->we = ft_strdup(str);
	else if (c == 'E' && !input->ea)
		input->ea = ft_strdup(str);
	else if (c == 'F' && !input->f)
		input->f = ft_strdup(str);
	else if (c == 'C' && !input->c)
		input->c = ft_strdup(str);
	return (0);
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

int	check_line(char *str, t_input *input)
{
	if (*str == '\n')
		return (0);
	else if (!ft_strncmp(str, "NO", 2))
		return (check_texture(str, input), 0);
	else if (!ft_strncmp(str, "SO", 2))
		return (check_texture(str, input), 0);
	else if (!ft_strncmp(str, "WE", 2))
		return (check_texture(str, input), 0);
	else if (!ft_strncmp(str, "EA", 2))
		return (check_texture(str, input), 0);
	else if (!ft_strncmp(str, "F", 1))
		return (check_texture(str, input), 0);
	else if (!ft_strncmp(str, "C", 1))
		return (check_texture(str, input), 0);
	else if (!check_if_empty(input))
		return (0);
	return (1);
}

t_input	*stock_input(int fd, t_input *input)
{
	char	*str;

	while(1)
	{
		str = get_next_line(fd);
		if (!str)
			return (NULL);
		else if(*str == '\0')
			break;
		printf("%s\n", str);
		if (check_line(str, input))
			return (ft_putendl_fd("Error invalid map", 2), NULL);
		free(str);
	}
		printf("test\n");
	return (free(str), input);
}

int main(int ac, char **av)
{
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
		printf("done\n");
	
	return (0);
}
