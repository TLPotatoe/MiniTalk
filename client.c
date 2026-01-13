/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:39:53 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/13 19:32:11 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	encode_str(char *str)
{
	uint8_t	mask;
	uint8_t	letter;

	(void)letter;
	ft_printf("STR:%s\n", str);
	while (*str)
	{
		ft_printf("Letter : %c %d\n", *str, *str);
		mask = (uint8_t)128;
		while (mask)
		{
			ft_printf("Mask %d\n", (mask & *str) && 1);
			mask = mask >> 1;
		}
		str++;
	}
}

int	main(int c, char **av)
{
	int		len;
	char	line[8192];

	(void)av;
	if (c != 2)
		return (0);
	while (1)
	{
		len = read(0, line, 8192);
		line[len] = 0;
		encode_str(line);
	}
	return (0);
}
