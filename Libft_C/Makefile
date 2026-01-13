# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:16:18 by fmurat--          #+#    #+#              #
#    Updated: 2025/12/16 15:24:04 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libft.a

HEADER = -I. -I get_next_line -I ft_printf

ifndef DEBUG
	CFLAGS = -Wall -Wextra -Werror -g $(HEADER)
else
	CFLAGS = -g $(HEADER)
endif

SRCS_GNL = get_next_line/get_next_line.c \
		   get_next_line/get_next_line_utils.c

SRCS_PRINTF = ft_printf/ft_printf.c \
			  ft_printf/ft_printf_utils.c \
			  ft_printf/ft_strchr.c \
			  ft_printf/ft_strlcpy.c \
			  ft_printf/ft_strlen.c \
			  ft_printf/ft_substr.c \
			  ft_printf/put_any_fd.c

SRCS_IS = is/ft_isalnum.c \
		  is/ft_isalpha.c \
		  is/ft_isascii.c \
		  is/ft_isdigit.c \
		  is/ft_isprint.c

SRCS_LST = lst/ft_lstadd_back.c \
		   lst/ft_lstadd_front.c \
		   lst/ft_lstclear.c \
		   lst/ft_lstdelone.c \
		   lst/ft_lstiter.c \
		   lst/ft_lstlast.c \
		   lst/ft_lstmap.c \
		   lst/ft_lstnew.c \
		   lst/ft_lstsize.c

SRCS_MEM = mem/ft_bzero.c \
		   mem/ft_calloc.c \
		   mem/ft_memchr.c \
		   mem/ft_memcmp.c \
		   mem/ft_memcpy.c \
		   mem/ft_memmove.c \
		   mem/ft_memset.c


SRCS_PUT = put/ft_putchar_fd.c \
		   put/ft_putendl_fd.c \
		   put/ft_putnbr_fd.c \
		   put/ft_putstr_fd.c

SRCS_STR = str/ft_atoi.c \
		   str/ft_itoa.c \
		   str/ft_split.c \
		   str/ft_strchr.c \
		   str/ft_strdup.c \
		   str/ft_striteri.c \
		   str/ft_strjoin.c \
		   str/ft_strlcat.c \
		   str/ft_strlcpy.c \
		   str/ft_strlen.c \
		   str/ft_strmapi.c \
		   str/ft_strncmp.c \
		   str/ft_strnstr.c \
		   str/ft_strrchr.c \
		   str/ft_strtrim.c \
		   str/ft_substr.c \
		   str/ft_tolower.c \
		   str/ft_toupper.c


SRCS = $(SRCS_GNL) \
		$(SRCS_PRINTF) \
		$(SRCS_IS) \
		$(SRCS_LST) \
		$(SRCS_MEM) \
		$(SRCS_PUT) \
		$(SRCS_STR)


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
