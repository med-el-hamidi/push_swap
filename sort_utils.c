#include "push_swap.h"

int	is_sorted(t_list *a)
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

void	ra_or_rra(t_list **a, int len, int *flag)
{
	int		count;
	t_list	*tmp;

	if (*flag == 1)
		r_(a, 'a');
	else if (*flag == -1)
		rr_(a, 'a');
	else
	{
		tmp = *a;
		count = 0;
		while ((!(*flag) && tmp && tmp->index != 0)
			|| (*flag == 2 && tmp && tmp->index != 1))
		{
			count++;
			tmp = tmp->next;
		}
		if ((!(*flag) && count <= (len - 3)))
			*flag = 1;
		else if (*flag == 2 && count <= ((len / 2) - 1))
			*flag = 1;
		else
			*flag = -1;
		ra_or_rra(a, len, flag);
	}
}

int	get_max_index(t_list *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	track_order(t_order *order)
{
	order->max = order->midium;
	order->midium = (order->max - order->next) / 2 + order->next;
	order->phase_flag++;
}
