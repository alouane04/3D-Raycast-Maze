#include "cube3D.h"

void	stock_map(t_list *lst, t_input *input)
{
	int len;
	int i;

	i = 0;
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
		free(str);
	}
	if (check_if_empty(input) || !input->map)
		return (free(str), ft_putendl_fd("Error invalid map", 2), 1);
	return (free(str), 0);
}
