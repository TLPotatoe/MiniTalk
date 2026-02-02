/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:39:53 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/02 15:17:37 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	send_str(int pid, char letter)
{
	int		server;
	uint8_t	mask;

	mask = (uint8_t)128;
	while (mask)
	{
		if ((mask & letter) && 1)
			server = kill(pid, SIGUSR1);
		else
			server = kill(pid, SIGUSR2);
		mask = mask >> 1;
		if (server == 0)
			pause();
		else
		{
			ft_printf("Incorrect PID: Process not found.\n");
			return (1);
		}
	}
	return (0);
}

static void	encode_str(char *str, int pid)
{
	while (*str)
	{
		if (send_str(pid, *str))
			return ;
		usleep(5);
		str++;
	}
	send_str(pid, 0);
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
