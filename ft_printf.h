#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

# define FD 1

int		ft_output_length_cntl(int flag);
void	ft_check_bytes_written(int bytes_written);
int		ft_check_ifwrite_failed(void);

int		ft_printf(const char *str, ...);
#endif
