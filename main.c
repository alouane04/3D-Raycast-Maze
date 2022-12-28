#include "cube3D.h"

t_list	*stock_input(int fd)
{
	t_list	*input;
	char	*str;

	input = NULL;
	while(1)
	{
		str =get_next_line(fd);
		if(*str == '\0')
			break;
		else if(!str)
			return(free(input), NULL);
		ft_lstadd_back(&input, ft_lstnew(str));
		free(str);
	}
	return (free(str),input);
}

int main(int ac, char **av)
{
}