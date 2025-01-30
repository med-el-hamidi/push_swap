NAME:=push_swap
CC:=cc
CFLAGS:= -Wall -Wextra -Werror -fsanitize=address

SRCS_PRINTF:= ft_printf.c ft_printf_utils.c
SRCS_LIBFT:=	ft_isdigit.c ft_strlen.c ft_bzero.c ft_strncmp.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

HEADERS:= libft.h ft_printf.h push_swap.h
SRCS:= $(SRCS_LIBFT) $(SRCS_PRINTF)  ft_rotate_type.c ft_rotate_and_push.c ft_case_rotation_ab_utils.c ft_case_rotation_ba_utils.c \
		ft_lstutils.c sort_big.c sort_three.c is_sorted.c push_swap_utils.c push_swap.c
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
