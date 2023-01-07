#include "cub3D.h"

void free_input(t_input *input)
{
    if(input->no)
        free(input->no);
    if(input->so)
        free(input->so);
    if(input->we)
        free(input->we);
    if(input->ea)
        free(input->ea);
    if(input->f)
        free(input->f);
    if(input->c)
        free(input->c);
	if (input->map)
		ft_free(input->map);
}

int	get_biggest_line(t_list *lst)
{
	int	n;

	n = ft_strlen((char*)lst->content);
	while (lst)
	{
		if (n < (int)ft_strlen((char*)lst->content))
			n = ft_strlen(lst->content);
		lst = lst->next;
	}
	return (n);
}

void	set_row_col(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(data->input->map[i]);
	while (data->input->map[i])
	{
		if (j < (int)ft_strlen(data->input->map[i]))
			j = ft_strlen(data->input->map[i]);
		i++;
	}
	data->num_rows = i;
	data->num_cols = j;
}

char	*stock_line(char const *s, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
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
