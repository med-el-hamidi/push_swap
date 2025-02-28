/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:37:24 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:37:25 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	detect_pattern(t_stack *a, int size);
static int	chunk_size(int size);
static void	push_to_b(t_stack **a, t_stack **b, int size);
static void	push_to_a(t_stack **a, t_stack **b, int size);

void	quick_sort(t_stack **a, t_stack **b, int size)
{
	push_to_b(a, b, size);
	push_to_a(a, b, size);
}

static int	detect_pattern(t_stack *a, int size)
{
	int	count;
	int	diff;

	count = 0;
	while (a && a->next)
	{
		diff = a->index - a->next->index;
		if (diff > 1 && diff < 5)
			count++;
		a = a->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

static int	chunk_size(int size)
{
	if (size > 100)
		return (34);
	else
		return (16);
}

static void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	chnk_size;
	int	patt;

	i = 0;
	chnk_size = chunk_size(size);
	patt = detect_pattern(*a, size);
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(b, a);
			i++;
		}
		else if ((*a)->index <= i + chnk_size)
		{
			pb(b, a);
			r_(b, 'b');
			i++;
		}
		else if (patt)
			rr_(a, 'a');
		else
			r_(a, 'a');
	}
}

static void	push_to_a(t_stack **a, t_stack **b, int size)
{
	int	pos;

	while (size)
	{
		pos = find_pos_of_max(*b);
		if (pos <= size / 2)
		{
			while (pos--)
				r_(b, 'b');
		}
		else
		{
			while (pos++ != size)
				rr_(b, 'b');
		}
		pa(a, b);
		size--;
	}
}
