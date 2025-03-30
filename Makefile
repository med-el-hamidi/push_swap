NAME := push_swap
CHECKER := checker
CC := cc
CFLAGS := -Wall -Wextra -Werror

PATH_LIBFT := ./libft/
LIBFT := $(PATH_LIBFT)libft.a
HEADER_LIBFT := $(PATH_LIBFT)libft.h
SRCS_LIBFT :=	$(PATH_LIBFT)ft_isdigit.c \
				$(PATH_LIBFT)ft_atoi.c \
				$(PATH_LIBFT)ft_bzero.c \
				$(PATH_LIBFT)ft_strlen.c \
				$(PATH_LIBFT)ft_strlcpy.c \
				$(PATH_LIBFT)ft_strncmp.c \
				$(PATH_LIBFT)ft_strdup.c \
				$(PATH_LIBFT)ft_split.c \
				$(PATH_LIBFT)ft_putstr_fd.c \
				$(PATH_LIBFT)ft_putchar_fd.c \
				$(PATH_LIBFT)ft_lstnew.c \
				$(PATH_LIBFT)ft_lstlast.c \
				$(PATH_LIBFT)ft_lstclear.c \
				$(PATH_LIBFT)ft_lstadd_front.c \
				$(PATH_LIBFT)ft_lstadd_back.c \
				$(PATH_LIBFT)ft_printf.c

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
				checker_utils1_bonus.c \
				checker_utils2_bonus.c \
				input_utils_bonus.c \
				checker_bonus.c

OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(PATH_LIBFT) -lft -o $@

$(CHECKER): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(PATH_LIBFT) -lft -o $@

$(LIBFT): $(SRCS_LIBFT) $(HEADER_LIBFT)
	make -C $(PATH_LIBFT)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(CHECKER)

clean:
	make -C $(PATH_LIBFT) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(PATH_LIBFT) fclean
	rm -f $(NAME) $(CHECKER)

re:	fclean all

.PHONY: clean
