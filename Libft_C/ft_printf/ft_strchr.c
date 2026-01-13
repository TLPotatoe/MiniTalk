/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:35:13 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/20 18:03:37 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)(c))
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)(c))
		return ((char *)s);
	return (NULL);
}
