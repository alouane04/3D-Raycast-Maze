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
		lst = stock_lst(fd, str, lst);
		return(0);
	}
	else
	{
		//write(2, "ok\n", 3);
		return(1);
	}
}

t_list	*stock_lst(int fd, char *str, t_list *lst)
{
	ft_lstadd_back(&lst, ft_lstnew(str));
	write(2, lst->content, 5);
	write(2, "\n",1);
	check_if_map(fd, get_next_line(fd), lst);
	return(lst);
}

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