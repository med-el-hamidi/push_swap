/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:57:39 by mel-hami          #+#    #+#             */
/*   Updated: 2024/11/30 20:45:00 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include "../ft_printf.h"

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void    ft_bzero(void *s, size_t n);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
