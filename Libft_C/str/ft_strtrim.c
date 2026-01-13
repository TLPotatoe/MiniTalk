/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:39:55 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 18:29:14 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[len]) && len >= 0)
		len--;
	p = malloc(len + 2);
	if (!p)
		return (NULL);
	if (len + 2 > 1)
		ft_strlcpy(p, s1, len + 2);
	p[len + 1] = 0;
	return (p);
}
