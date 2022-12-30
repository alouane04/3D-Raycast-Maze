#include "cube3D.h"

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

int check_color(char *str, t_input *input)
{
	char	c;

	c = *str;
	str++;
	while (*str == ' ')
	str++;
	if (c == 'F' && !input->f)
	{
		input->f = stock_rgb(ft_strdup(str));
		if(!input->f)
			return(1);
	}
	else if (c == 'C' && !input->c)
	{
		input->c = stock_rgb(ft_strdup(str));
		if(!input->c)
			return(1);
	}
	else
		return(1);
	return(0);
}

int check_texture(char *str, t_input *input)
{
	char	c;

	c = *str;
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
	else
		return(1);
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

int	check_if_map(int fd, char *str, t_list *lst)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i]  == ' ')
	 	i++;
	if (str[i] == '1' && ft_strspn(str, " 10NWSE") == ft_strlen(str))
	{
		stock_lst(fd, str, lst);
		return(0);
	}
	else
	{
		//write(2, "ok\n", 3);
		return(1);
	}
}

int	check_line(char *str, t_input *input)
{
	if (*str == '\0')
		return (0);
	else if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) 
				|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
		return (check_texture(str, input));
    else if (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
        return (check_color(str, input));
	else
		return (1);
}
