
#include "cube3D.h"

<<<<<<< HEAD
char **check_rgb(char *str)
{
	int i;
	int j;
	char **str1;

	i = 0;
	j = 0;
	if(!str)
		return (NULL);
	while(ft_isdigit(str[i]) || str[i] == ',')
	{
		if(str[i] == ',')
			j++;
		i++;
	}
	if ((str[i] != '\n' && str[i] != '\0') || j != 2)
		return (free(str), NULL);
	str1 = ft_split(str, ',');
	if (!str1)
		return (free(str),NULL);
	return(free(str), str1);
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
		input->f = stock_rgb(ft_strdup(str));
	else if (c == 'C' && !input->c)
		input->c = stock_rgb(ft_strdup(str));
	else
		return(1);
	return (0);
}

int	check_line(char *str, t_input *input)
{
	if (*str == '\0')
		return (0);
	else if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) 
				|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2)
					||!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
	{
		return (check_texture(str, input));
	}
	else
		return (1);
}

t_input	*stock_input(int fd, t_input *input)
{
	char	*str;

	while(1)
	{
		str = get_next_line(fd);
		write(1, str,ft_strlen(str));
		if (!str)
			return (NULL);
		else if(*str == EOF)
			break;
		if (check_line(str, input))
		{
			printf("error\n");
			return (ft_putendl_fd("Error invalid map", 2), NULL);
		}
		free(str);
	}
	return (free(str), input);
}

=======
>>>>>>> 0420054ade0d833eccf4976043f97711797b8cdb
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
		return(free_input(&input), 1);
	printf("%d\n", input.c[0]);
	return (0);
}
