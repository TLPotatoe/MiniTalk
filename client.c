/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:39:53 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/14 18:15:02 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	encode_str(char *str, int pid)
{
	uint8_t	mask;

	while (*str)
	{
		mask = (uint8_t)128;
		while (mask)
		{
			if ((mask & *str) && 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			mask = mask >> 1;
			pause();
		}
		usleep(5);
		str++;
	}
}

static void	ack_handler(int sig)
{
	(void)sig;
}

static void	setup_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
}

int	main(int c, char **av)
{
	char	line[4096];
	int		len;

	if (c != 2)
		return (0);
	setup_sigaction();
	while (1)
	{
		len = read(0, line, 4095);
		if (len == -1)
			return (1);
		line[len] = 0;
		encode_str(line, ft_atoi(av[1]));
	}
	return (0);
}
