/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:36:00 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:36:01 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

void	free_argv(char ***argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = 0;
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
	*argv = NULL;
}

void	free_exit(int e, char ***argv)
{
	free_argv(argv);
	if (e > 0)
		ft_putstr_fd("Error\n", 2);
	exit (e);
}
