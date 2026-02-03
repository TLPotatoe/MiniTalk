/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:15:12 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/03 13:16:59 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

static void	ft_minitalk_buffer(char **buff, char letter)
{
	char	*ret;
	size_t	len_buff;

	if (!buff)
		return ;
	if (*buff)
		len_buff = ft_strlen(*buff);
	else
		len_buff = 0;
	ret = malloc(sizeof(char) * (len_buff + 2));
	if (!ret)
		return ;
	if (*buff)
		ft_memcpy(ret, *buff, len_buff);
	ret[len_buff] = letter;
	ret[len_buff + 1] = '\0';
	free(*buff);
	*buff = ret;
}

static void	ft_printtalk(char letter)
{
	static char	*buff = NULL;

	if (letter == 0)
	{
		ft_printf("%s", buff);
		free(buff);
		buff = NULL;
	}
	else
		ft_minitalk_buffer(&buff, letter);
}

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
		ft_printtalk(letter);
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
