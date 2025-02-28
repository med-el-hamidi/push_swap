/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:37:02 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:37:03 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_(t_stack **stack, char c)
{
	if (swap(stack))
		ft_printf("s%c\n", c);
}

void	ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next
		|| !b || !*b || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	pa(t_stack **to_a, t_stack **from_b)
{
	if (push(to_a, from_b))
		ft_printf("pa\n");
}

void	pb(t_stack **to_b, t_stack **from_a)
{
	if (push(to_b, from_a))
		ft_printf("pb\n");
}
