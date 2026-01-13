/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:02:24 by tlamit            #+#    #+#             */
/*   Updated: 2025/10/22 18:39:57 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size_m(int nb)
{
	int	i;
	int	sign;

	if (nb == -2147483648)
		return (11);
	i = 0;
	if (nb == 0)
		i++;
	sign = nb < 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i + sign);
}

char	*ft_itoa(int n)
{
	char		*r;
	int			len;
	int			i;
	int			j;
	const char	*str = "0123456789";

	len = get_size_m(n);
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	r[len] = 0;
	if (n < 0)
		r[0] = '-';
	i = len - 1;
	if (!n)
		r[0] = '0';
	while (n != 0)
	{
		j = (n % 10) + (-2 * (n % 10) * (n % 10 < 0));
		r[i--] = str[j];
		n /= 10;
	}
	return (r);
}
