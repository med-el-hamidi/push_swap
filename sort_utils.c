/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:37:39 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:37:41 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_till_0or1_index(t_stack *a, int size);

int	is_sorted(t_stack *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (min > a->nbr)
			return (0);
		min = a->nbr;
		a = a->next;
	}
	return (1);
}

void	ra_or_rra(t_stack **a, int size, int *flag)
{
	int		count;
	t_stack	*ptr;

	if (*flag == 1)
		r_(a, 'a');
	else if (*flag == -1)
		rr_(a, 'a');
	else
	{
		ptr = *a;
		count = count_till_0or1_index(ptr, size);
		if (!(*flag) && count <= 1)
			*flag = 1;
		else if (*flag == 2 && count <= 2)
			*flag = 1;
		else
			*flag = -1;
		ra_or_rra(a, size, flag);
	}
}

static int	count_till_0or1_index(t_stack *a, int size)
{
	int	count;

	count = 0;
	if (size == 4)
	{
		while (a && a->index != 0)
		{
			count++;
			a = a->next;
		}
	}
	else if (size == 5)
	{
		while (a && a->index != 0 && a->index != 1)
		{
			count++;
			a = a->next;
		}
	}
	return (count);
}

int	find_pos_of_max(t_stack *stack)
{
	int		max;
	int		pos;
	t_stack	*ptr;

	max = stack->nbr;
	pos = 0;
	ptr = stack;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	while (ptr->nbr != max)
	{
		ptr = ptr->next;
		pos++;
	}
	return (pos);
}
