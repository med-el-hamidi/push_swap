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
