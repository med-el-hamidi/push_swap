/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:53 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:35:54 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (argv)
		free_argv(argv);
	if (e > 0)
		ft_putstr_fd("Error\n", 2);
	exit (e);
}

void	freelsts_exit(int e, t_stack **a, t_instruct **ins)
{
	ft_lstclear(a);
	ft_lstclear_(ins);
	if (e > 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (e);
	}
}
