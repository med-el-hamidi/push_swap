NAME:=push_swap
CC:=cc
CFLAGS:= -Wall -Wextra -Werror -fsanitize=address

SRCS_PRINTF:= ft_printf.c ft_printf_utils.c
SRCS_LIBFT:=	ft_isdigit.c ft_strlen.c ft_bzero.c ft_strncmp.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstnew.c ft_lstsize.c
SRCS_PUSH_SWAP:= stack_indexing.c push_swap_op1.c push_swap_op2.c push_swap_op3.c quick_sort.c sort_small.c sort_utils.c push_swap.c

HEADERS:= libft.h ft_printf.h push_swap.h
SRCS:= $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_PUSH_SWAP)
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
