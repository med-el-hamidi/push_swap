#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void    ft_bzero(void *s, size_t n);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_check_bytes_written(int bytes_written);
#endif
