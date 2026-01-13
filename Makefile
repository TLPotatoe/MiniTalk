# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:16:18 by fmurat--          #+#    #+#              #
#    Updated: 2026/01/13 18:44:07 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

SRCS_DIR    = src

SRCS_SERVER = server.c

SRCS_CLIENT = client.c

HEADER := -I includes \
		-I Libft_C

ifndef DEBUG
	CFLAGS := -Wall -Wextra -Werror -g $(HEADER)
else
	CFLAGS := -g $(HEADER)
endif

NAME_SERVER := server
OBJS_SERVER := $(SRCS_SERVER:.c=.o)

NAME_CLIENT := client
OBJS_CLIENT := $(SRCS_CLIENT:.c=.o)


LIBFT := Libft_C/libft.a
LIBS := $(LIBFT)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBS)
	$(CC) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBS)
	$(CC) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C Libft_C -j

clean:
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT)
	$(MAKE) -C Libft_C clean

fclean: clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	$(MAKE) -C Libft_C fclean

re: fclean all

.PHONY: all clean fclean re