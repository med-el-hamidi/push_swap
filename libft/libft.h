#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define FD 1
# define EXIT_ERROR_STDIN -1

typedef struct s_stack {
	int				nbr;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, int *size, char c);

t_stack	*ft_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);

int		ft_printf(const char *str, ...);
#endif
