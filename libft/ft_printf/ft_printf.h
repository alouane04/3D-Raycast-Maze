/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:41:57 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/17 14:07:12 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_nblen(int nb);
int		ft_putunsigned(unsigned int nb);
int		ft_unsnblen(unsigned int nb);
int		ft_putx(unsigned int nb, const char str);
int		ft_xlen(unsigned long long hex);
int		ft_puthexa(unsigned long long hex);
int		ft_flag_x(const char *str, int i, int check);
/////////////////////////////////////////////////////bonus
int		ft_flag(const char *str, va_list arg, int i);
int		ft_flag_x(const char *str, int i, int check);

#endif
