/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:36:40 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:36:42 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

int	push(t_stack **to, t_stack **from)
{
	t_stack	*ptr;

	if (!from || !*from)
		return (0);
	ptr = (*from)->next;
	(*from)->next = NULL;
	ft_lstadd_front(to, *from);
	*from = ptr;
	return (1);
}

void	rotate(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	ptr = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = NULL;
	*stack = ptr;
}

void	rrotate(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	ptr = *stack;
	while (ptr->next->next)
		ptr = ptr->next;
	ft_lstadd_front(stack, ptr->next);
	ptr->next = NULL;
}
