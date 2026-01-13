/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:52:27 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/21 16:31:02 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

char	*gnl_ft_strndup(char *s, size_t n)
{
	char	*ret;
	size_t	i;

	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static char	*gnl_ft_memcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len_1;
	size_t	len_2;

	len_2 = gnl_ft_strchr(s2, 0) - s2;
	if (!s1)
		return (s2);
	len_1 = gnl_ft_strchr(s1, 0) - s1;
	ret = malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!ret)
		return (NULL);
	gnl_ft_memcpy(ret, s1, len_1);
	gnl_ft_memcpy(ret + len_1, s2, len_2);
	ret[len_1 + len_2] = 0;
	free(s1);
	free(s2);
	return (ret);
}
