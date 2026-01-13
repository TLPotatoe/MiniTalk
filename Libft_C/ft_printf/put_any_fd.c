/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_any_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:32:54 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/21 23:33:08 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned long int n, int fd, unsigned int upper, int *i)
{
	const char	*base = "0123456789abcdef";
	const char	*base_up = "0123456789ABCDEF";

	if (n >= 16)
		ft_puthex_fd(n / 16, fd, upper, i);
	if (upper)
		printf_ft_putchar_fd(base_up[n % 16], fd, i);
	else
		printf_ft_putchar_fd(base[n % 16], fd, i);
}

void	ft_putlongnbr_fd(long int n, int fd, int *i)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n < 10)
	{
		write(fd, &"0123456789"[n % 10], 1);
		(*i)++;
		return ;
	}
	printf_ft_putnbr_fd(n / 10, fd, i);
	write(fd, &"0123456789"[n % 10], 1);
	(*i)++;
}

void	printf_ft_putstr_fd(char *s, int fd, int *i)
{
	if (s)
	{
		write(fd, s, printf_ft_strlen(s));
		(*i) += printf_ft_strlen(s);
	}
	else
	{
		write(fd, "(null)", 6);
		(*i) += 6;
	}
}

void	printf_ft_putnbr_fd(int n, int fd, int *i)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		(*i) += 11;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		(*i)++;
	}
	if (n < 10)
	{
		write(fd, &"0123456789"[n % 10], 1);
		(*i)++;
		return ;
	}
	printf_ft_putnbr_fd(n / 10, fd, i);
	write(fd, &"0123456789"[n % 10], 1);
	(*i)++;
}

void	printf_ft_putchar_fd(char c, int fd, int *i)
{
	write(fd, &c, 1);
	(*i)++;
}
