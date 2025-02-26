#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	ft_check_bytes_written(write(fd, &c, 1));
}
