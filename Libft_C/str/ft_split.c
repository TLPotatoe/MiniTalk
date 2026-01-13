/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:24:31 by marvin            #+#    #+#             */
/*   Updated: 2025/10/23 13:25:30 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	count_words(char const *s, char c)
{
	int	word;
	int	flag;

	word = 0;
	flag = 1;
	while (*s)
	{
		while (*s && *s != c)
		{
			if (flag)
			{
				flag = 0;
				word++;
			}
			s++;
		}
		while (*s && *s == c)
		{
			flag = 1;
			s++;
		}
	}
	return (word);
}

char	**ft_checksplit(char **p, int n)
{
	int	i;

	i = 0;
	while (p[i] && i != n)
		i++;
	if (i != n)
	{
		i = 0;
		while (i < n)
			free(p[i++]);
		free(p);
		return (NULL);
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		len;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	p = ft_calloc(sizeof(char *), (words + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (*s)
	{
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len)
			p[i++] = ft_substr(s, 0, len);
		while (s[len] && s[len] == c)
			len++;
		s += len;
	}
	p = ft_checksplit(p, words);
	return (p);
}
