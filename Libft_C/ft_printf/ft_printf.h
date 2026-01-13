/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:00:30 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/21 23:17:40 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	is_format(const char *format, char c);
int		count_args_n(const char *s);
int		get_perfect_len(const char *str);
void	handle_pointer(unsigned long int addr, int *i);
void	handle_type(const char *s, va_list arglist, int *i);
char	*printf_ft_strchr(const char *s, int c);
size_t	printf_ft_strlcpy(char *dst, const char *src, size_t size);
size_t	printf_ft_strlen(const char *s);
char	*printf_ft_substr(char const *s, unsigned int start, size_t len);
void	ft_puthex_fd(unsigned long int n, int fd, unsigned int upper, int *i);
void	ft_putlongnbr_fd(long int n, int fd, int *i);
void	printf_ft_putstr_fd(char *s, int fd, int *i);
void	printf_ft_putnbr_fd(int n, int fd, int *i);
void	printf_ft_putchar_fd(char c, int fd, int *i);

#endif
