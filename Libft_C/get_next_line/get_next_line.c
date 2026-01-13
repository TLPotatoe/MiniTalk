/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:52:14 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/20 18:08:34 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **mbuff)
{
	size_t	len;
	char	*temp;
	char	*line;
	char	*end_line;

	end_line = gnl_ft_strchr(*mbuff, '\n');
	line = gnl_ft_strndup(*mbuff, end_line - *mbuff + 1);
	len = gnl_ft_strchr(end_line, 0) - end_line;
	temp = *mbuff;
	*mbuff = gnl_ft_strndup(end_line + 1, len);
	if (!*mbuff)
	{
		free(temp);
		free(line);
		return (NULL);
	}
	free(temp);
	return (line);
}

static int	reader(int fd, char **tbuff)
{
	int	len;

	*tbuff = malloc(BUFFER_SIZE + 1);
	if (!*tbuff)
		return (-1);
	len = read(fd, *tbuff, BUFFER_SIZE);
	return (len);
}

static void	freeall(char **mbuff, char **tbuff)
{
	free(*mbuff);
	*mbuff = NULL;
	free(*tbuff);
	*tbuff = NULL;
}

char	*get_next_line(int fd)
{
	static char	*mbuff;
	char		*tbuff;
	char		*line;
	int			len;

	while (!gnl_ft_strchr(mbuff, '\n'))
	{
		len = reader(fd, &tbuff);
		if (len == -1 || (!(gnl_ft_strchr(mbuff, 0) - mbuff) && len <= 0))
		{
			freeall(&mbuff, &tbuff);
			return (NULL);
		}
		else if (!len)
		{
			free(tbuff);
			line = mbuff;
			mbuff = NULL;
			return (line);
		}
		tbuff[len] = 0;
		mbuff = gnl_ft_strjoin(mbuff, tbuff);
	}
	line = extract_line(&mbuff);
	return (line);
}
