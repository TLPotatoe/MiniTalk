/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:09:39 by tlamit            #+#    #+#             */
/*   Updated: 2025/10/22 17:58:25 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_p;

	last_p = NULL;
	while (*s)
	{
		if (*s == (unsigned char)(c))
			last_p = (char *)s;
		s++;
	}
	if (*s == (unsigned char)(c))
		last_p = (char *)s;
	return (last_p);
}
