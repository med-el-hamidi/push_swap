NAME := push_swap
CHECKER := checker
LIBFT := ./libft/libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address


HEADER := push_swap.h
HEADER_BONUS := checker_bonus.h

SRCS :=	push_swap_error.c \
		push_swap_op1.c \
		push_swap_op2.c \
		push_swap_op3.c \
		stack_indexing.c \
		sort_utils.c \
		quick_sort.c \
		sort_small.c \
		input_utils.c \
		push_swap.c
SRCS_BONUS :=	push_swap_error_bonus.c \
				push_swap_op1_bonus.c \
				push_swap_op2_bonus.c \
				checker_utils_bonus.c \
				input_utils_bonus.c \
				checker_bonus.c

OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $@

$(CHECKER): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L./libft -lft -o $@

$(LIBFT):
	make -C ./libft

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(CHECKER)

clean:
	make -C ./libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME) $(CHECKER)

re:	fclean $(NAME)

.PHONY: clean
