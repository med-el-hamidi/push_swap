# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 12:40:29 by mel-hami          #+#    #+#              #
#    Updated: 2025/02/27 12:40:37 by mel-hami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
HEADER := libft.h
SRCS :=	ft_isdigit.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strdup.c \
		ft_split.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_lstnew.c \
		ft_lstlast.c \
		ft_lstclear.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_printf.c

OBJS :=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean
