#include "ft_printf.h"

static void	_ft_printf(va_list args, const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_output_length_cntl(0);
	_ft_printf(args, str);
	va_end(args);
	return (ft_output_length_cntl(-2));
}

static void	_ft_printf(va_list args, const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp)
	{
		if (*tmp == '%')
		{
            tmp++;
			if (*tmp == 'c')
			{
				ft_putchar_fd(va_arg(args, int), FD);
				ft_output_length_cntl(1);
			}
			if (ft_check_ifwrite_failed())
				return ;
		}
		else
		{
			ft_putchar_fd(*tmp, FD);
			if (ft_check_ifwrite_failed())
				return ;
			ft_output_length_cntl(1);
		}
		tmp++;
	}
}
