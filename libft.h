#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list {
	int				nbr;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void    ft_bzero(void *s, size_t n);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int ));
t_list	*ft_lstmap(t_list *lst);

void	ft_check_bytes_written(int bytes_written);
#endif
