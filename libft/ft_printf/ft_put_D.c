/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:47:14 by ariahi            #+#    #+#             */
/*   Updated: 2022/01/10 13:47:19 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nblen(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		i += ft_putchar('-');
	}
	if (nbr < 10)
		return (ft_putchar(nbr + 48) + i);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	i += ft_nblen(nb);
	return (i);
}

int	ft_unsnblen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putunsigned(unsigned int nb)
{
	unsigned long long	nbr;

	nbr = nb;
	if (nbr < 10)
		return (ft_putchar(nbr + 48));
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	return (ft_unsnblen(nbr));
}
