/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:57:59 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/21 23:03:07 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	char	*buffer;
	int		len;
	int		i;

	if (count_args_n(str) == -1)
		return (-1);
	va_start(arglist, str);
	i = 0;
	while (*str)
	{
		len = get_perfect_len(str);
		buffer = printf_ft_substr(str, 0, len);
		if (buffer)
			printf_ft_putstr_fd(buffer, 1, &i);
		free(buffer);
		str += len;
		if (is_format("cspdiuxX%", str[1]))
			handle_type(str, arglist, &i);
		if (*str)
			str += 2;
	}
	va_end(arglist);
	return (i);
}
