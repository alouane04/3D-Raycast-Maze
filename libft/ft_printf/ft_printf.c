/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:32:27 by ariahi            #+#    #+#             */
/*   Updated: 2022/01/05 18:13:27 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_check(va_list arg, const char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (str == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (str == 'p')
	{
		len = write(1, "0x", 2);
		len += ft_puthexa(va_arg(arg, unsigned long long));
	}
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (str == 'u')
		len += ft_putunsigned(va_arg(arg, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_putx(va_arg(arg, unsigned int), str);
	else if (str == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_flag(const char *str, va_list arg, int i)
{
	int		flag;
	va_list	arg_c;
	int		check;

	flag = 0;
	va_copy(arg_c, arg);
	check = va_arg(arg_c, int);
	if (str[i] == 'i' || str[i] == 'd')
	{
		while (str[i--] != '%')
		{
			if (str[i] == '+' && check >= 0)
				return (write(1, "+", 1));
			else if (str[i] == ' ' && check >= 0)
				flag = 1;
		}
		if (flag)
			return (write(1, " ", 1));
	}
	if (str[i] == 'x' || str[i] == 'X')
		return (ft_flag_x(str, i, check));
	return (0);
}

int	ft_flag_x(const char *str, int i, int check)
{
	if (str[i] == 'x')
	{
		while (str[i--] != '%' && check != 0)
			if (str[i] == '#')
				return (write(1, "0x", 2));
	}
	else
	{
		while (str[i--] != '%' && check != 0)
			if (str[i] == '#')
				return (write(1, "0X", 2));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else
		{
			i++;
			while ((str[i] == '#' || str[i] == ' ' || str[i] == '+' ) && str[i])
				i++;
			len += ft_flag(str, arg, i);
			len += ft_check(arg, str[i]);
		}
		i++;
	}
	return (va_end(arg), len);
}
