/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:12:26 by tlamit            #+#    #+#             */
/*   Updated: 2025/10/22 18:07:56 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == 0)
		return ((char *)big);
	while (*big && len--)
	{
		i = 0;
		while (big[i] == little[i] && i <= len)
			if (little[++i] == 0)
				return ((char *)big);
		big++;
	}
	return (NULL);
}
