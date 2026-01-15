/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:39:53 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/15 17:26:01 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	encode_str(char *str, int pid)
{
	uint8_t	mask;
	int		server;

	while (*str)
	{
		mask = (uint8_t)128;
		while (mask)
		{
			if ((mask & *str) && 1)
				server = kill(pid, SIGUSR1);
			else
				server = kill(pid, SIGUSR2);
			mask = mask >> 1;
			if (server == 0)
				pause();
			else
			{
				ft_printf("Incorrect PID: Process not found.\n");
				return ;
			}
		}
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
	if (c != 3)
	{
		ft_printf("Wrong number of arguments : ./client <pid>, <message>\n");
		return (0);
	}
	setup_sigaction();
	if (ft_atoi(av[1]) == 0)
	{
		ft_printf("PID should be a non-nul number.\n");
		return (0);
	}
	encode_str(av[2], ft_atoi(av[1]));
}
