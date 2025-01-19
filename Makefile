NAME:=push_swap
CC:=cc
CFLAGS:= -Wall -Wextra -Werror

SRCS_PRINTF:= ft_printf.c ft_printf_utils.c
SRCS_LIBFT:=	ft_isdigit.c ft_strlen.c ft_bzero.c ft_strncmp.c \
			ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c

HEADERS:= libft.h ft_printf.h push_swap.h
SRCS:= $(SRCS_LIBFT) $(SRCS_PRINTF) push_swap_operations.c push_swap.c
OBJS:=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean
