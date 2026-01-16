/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:15:12 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/16 15:58:39 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	letter = 0;
	static int				bit_count = 0;

	(void)context;
	if (sig == SIGUSR1)
		letter = (letter << 1) | 1;
	else if (sig == SIGUSR2)
		letter = (letter << 1) | 0;
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd(letter, 1);
		letter = 0;
		bit_count = 0;
	}
	usleep(5);
	kill(info->si_pid, SIGUSR1);
}

static void	setup_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	setup_sigaction();
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
}
