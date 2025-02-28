/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:39:06 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:39:07 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_printf(va_list args, const char *str);
static int	ft_output_length_cntl(int flag);
static int	ft_check_ifwrite_failed(void);

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_output_length_cntl(0);
	_ft_printf(args, str);
	va_end(args);
	if (ft_output_length_cntl(-2) == -1)
		exit(EXIT_ERROR_STDIN);
	return (ft_output_length_cntl(-2));
}

void	ft_check_bytes_written(int bytes_written)
{
	if (bytes_written == -1)
		ft_output_length_cntl(-1);
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

static int	ft_output_length_cntl(int flag)
{
	static int	output_length;

	if (!flag)
		output_length = 0;
	else if (flag > 0)
		output_length += flag;
	else if (flag == -1)
		output_length = -1;
	return (output_length);
}

static int	ft_check_ifwrite_failed(void)
{
	if (ft_output_length_cntl(-2) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else
		return (0);
}
