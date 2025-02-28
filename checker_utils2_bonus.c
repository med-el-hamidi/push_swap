/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:49:59 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 13:50:01 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	_check_order(t_stack **a, t_instruct *ins);
static void	_action(t_stack **a, t_stack **b, char *move);

void	output(t_stack **a, t_instruct *ins)
{
	if (_check_order(a, ins))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static int	_check_order(t_stack **a, t_instruct *ins)
{
	t_stack		*b;
	t_instruct	*ptr;

	b = NULL;
	ptr = ins;
	while (ptr)
	{
		_action(a, &b, ptr->str);
		ptr = ptr->next;
	}
	if (b)
	{
		ft_lstclear(&b);
		return (0);
	}
	return (is_sorted(*a));
}

static void	_action(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "pa\n", 4))
		push(a, b);
	else if (!ft_strncmp(move, "pb\n", 4))
		push(b, a);
	else if (!ft_strncmp(move, "sa\n", 4))
		swap(a);
	else if (!ft_strncmp(move, "sb\n", 4))
		swap(b);
	else if (!ft_strncmp(move, "ss\n", 4))
		ss(a, b);
	else if (!ft_strncmp(move, "ra\n", 4))
		rotate(a);
	else if (!ft_strncmp(move, "rb\n", 4))
		rotate(b);
	else if (!ft_strncmp(move, "rra\n", 5))
		rrotate(a);
	else if (!ft_strncmp(move, "rrb\n", 5))
		rrotate(b);
	else if (!ft_strncmp(move, "rr\n", 4))
		rr(a, b);
	else if (!ft_strncmp(move, "rrr\n", 5))
		rrr(a, b);
}
