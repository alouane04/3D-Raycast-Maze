/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:47:39 by ariahi            #+#    #+#             */
/*   Updated: 2022/01/10 13:47:42 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///////////////////////////////////////////xlen

int	ft_xlen(unsigned long long hex)
{
	int	len;

	len = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}

///////////////////////////////////////////hexa

int	ft_putx(unsigned int nb, const char str)
{
	if (nb >= 16)
	{
		ft_putx(nb / 16, str);
		ft_putx(nb % 16, str);
	}
	else
	{
		if (nb <= 9)
			return (ft_putchar(nb + '0'));
		else
		{
			if (str == 'x')
				ft_putchar((nb - 10 + 'a'));
			else
				ft_putchar((nb - 10 + 'A'));
		}
	}
	return (ft_xlen(nb));
}

///////////////////////////////////////////ptr

int	ft_puthexa(unsigned long long hex)
{
	if (hex >= 16)
	{
		ft_puthexa(hex / 16);
		ft_puthexa(hex % 16);
	}
	else
	{
		if (hex <= 9)
			return (ft_putchar(hex + '0'));
		else
			ft_putchar((hex - 10 + 'a'));
	}
	return (ft_xlen(hex));
}

////////////////////////////////////////////str

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
