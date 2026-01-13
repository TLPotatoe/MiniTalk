/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:30:37 by tlamit            #+#    #+#             */
/*   Updated: 2025/10/23 13:06:51 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	get_result(char *dst, char *src, size_t size)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (dst && dst[j] && j < size)
		j++;
	return (i + j);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned int	res;

	if (!size)
		return (ft_strlen(src));
	res = get_result(dst, (char *)src, size);
	size--;
	i = 0;
	j = 0;
	while (dst[j])
		j++;
	if (j >= size)
		return (res);
	while (src[i] && (j + i) < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (res);
}
