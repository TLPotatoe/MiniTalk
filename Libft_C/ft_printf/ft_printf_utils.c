/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:45:26 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/21 15:35:28 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_format(const char *format, char c)
{
	while (*format)
		if (*format++ == c)
			return (1);
	return (0);
}

int	count_args_n(const char *s)
{
	int	i;

	i = 0;
	if (!*s)
		return (-1);
	while (*s && *(s + 1))
	{
		if (*s == '%')
		{
			if (is_format("cspdiuxX%", *(s + 1)))
			{
				i++;
				s++;
			}
			else
				return (-1);
		}
		s++;
	}
	return (i);
}

int	get_perfect_len(const char *str)
{
	int	len;

	if (printf_ft_strchr(str, '%'))
		len = (size_t)(printf_ft_strchr(str, '%') - str);
	else
		len = printf_ft_strlen(str);
	return (len);
}

void	handle_pointer(unsigned long int addr, int *i)
{
	if (addr)
	{
		printf_ft_putstr_fd("0x", 1, i);
		ft_puthex_fd(addr, 1, 0, i);
	}
	else
		printf_ft_putstr_fd("(nil)", 1, i);
}

void	handle_type(const char *s, va_list arglist, int *i)
{
	if (!*s)
		return ;
	if (s[1] == 'c')
		printf_ft_putchar_fd(va_arg(arglist, int), 1, i);
	else if (s[1] == 's')
		printf_ft_putstr_fd(va_arg(arglist, char *), 1, i);
	else if (s[1] == 'p')
		handle_pointer(va_arg(arglist, unsigned long int), i);
	else if (s[1] == 'd' || s[1] == 'i')
		printf_ft_putnbr_fd(va_arg(arglist, signed int), 1, i);
	else if (s[1] == 'u')
		ft_putlongnbr_fd((unsigned int)va_arg(arglist, int), 1, i);
	else if (s[1] == 'x')
		ft_puthex_fd(va_arg(arglist, unsigned int), 1, 0, i);
	else if (s[1] == 'X')
		ft_puthex_fd(va_arg(arglist, unsigned int), 1, 1, i);
	else if (s[1] == '%')
		printf_ft_putchar_fd('%', 1, i);
}
