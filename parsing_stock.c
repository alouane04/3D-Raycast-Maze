#include "cube3D.h"

void	stock_map(t_list *lst, t_input *input)
{
	t_list	*tmp;
	int 	len;
	int 	i;

	i = 0;
	tmp = lst;
	input->map = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!input->map)
		return ;
	len = get_biggest_line(lst);
	while (lst)
	{
		input->map[i] = stock_line(lst->content, len);
		i++;
		lst = lst->next;
	}
	ft_lstclear(&tmp, free);
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

int	map_validity(char	**map, int i)
{
	int		j;

	j = 0;
	if (map[i + 1] == '\0')
	{
		if((ft_strspn(map[i], " 1") == ft_strlen(map[i])))
			return (0);
		return(1);
	}
	if (!ft_strchr(map[i], '1') || map[i][j] == '\0'
			|| (map[i][j] != ' ' && map[i][j] != '1'))
		return(1);
	while (map[i][j])
	{
		if(map[i][j] && !(map[i][j] == ' ' || map[i][j] == '1')
			&& (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' 
				|| map[i-1][j] == ' ' || map[i + 1][j] == ' '
					|| map[i][j + 1] == '\0' || map[i + 1][j] == '\0'
						|| map[i - 1][j] == '\0'))
			return(1);
		j++;
	}
	if(map_validity(&map[i], i))
		return(1);
	return(0);
}

int	stock_input(int fd, t_input *input)
{
	char	*str;
	t_list	*lst;

	lst = NULL;
	while(1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (check_line(str, input, fd))
			return (free(str), ft_putendl_fd("Error invalid map", 2), 1);
	}
	if (!input->map || ((ft_2d_len(input->map) < 3)))
		return (ft_putendl_fd("Error invalid map", 2), 1);
	if(map_validity(input->map, 1))
		return (ft_putendl_fd("Error invalid map2", 2), 1);
	return (0);
}
