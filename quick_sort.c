#include "push_swap.h"

static void	partition(t_list **a, t_list **b, t_order *order, int len);
static void	position_next(t_list **a, t_list **b, t_order *order);
static void	quick_sort_a(t_list **a, t_list **b, t_order *order);
static void	quick_sort_b(t_list **a, t_list **b, t_order *order);

void	quick_sort(t_list **a, t_list **b, int len)
{
	t_order	order;

	order.next = 0;
	order.max = get_max_index(*a);
	order.midium = order.max / 2;
	order.phase_flag = 0;
	partition(a, b, &order, len);
	while (ft_lstsize(*a) != len || !is_sorted(*a))
	{
		if (!ft_lstsize(*b))
			quick_sort_b(a, b, &order);
		else
			quick_sort_a(a, b, &order);
	}
}

static void	partition(t_list **a, t_list **b, t_order *order, int len)
{
	int		i;
	//int		j;
	//int		*ra_or_rra;

	i = -1;
	//j = 0;
	//ra_or_rra = 0;
	//ra_or_rra = part_by_ra_or_rra(*a, len);
	while (++i < len)
	{
		if ((*a)->index <= order->midium)
			pb(b, a);
		else
		{
			// if (ra_or_rra && ra_or_rra[j++])
			// {
			// 	if (ft_lstsize(*b) > 1 && ft_lstlast(*b)->index > (order->midium / 2))
			// 		rrr(a, b);
			// 	else
			// 		rr_(a, 'a');
			// }
			// else
			// {
				if (ft_lstsize(*b) > 1 && (*b)->index < (order->midium / 2))
					rr(a, b);
				else
					r_(a, 'a');
			//}
		}
	}
	//free(ra_or_rra);
	track_order(order);
}

static void	position_next(t_list **a, t_list **b, t_order *order)
{
	if (ft_lstsize(*b) > 0 && (*b)->index == order->next)
		pa(a, b);
	else if ((*a)->index == order->next)
	{
		order->next++;
		(*a)->flag = -1;
		r_(a, 'a');
	}
	else if (ft_lstsize(*b) > 2 && ft_lstlast(*b)->index == order->next)
		rr_(b, 'b');
	else if ((*a)->next->index == order->next
		&& ft_lstsize(*b) > 1 && (*b)->next->index == (order->next + 1))
		ss(a, b);
	else if ((*a)->next->index == order->next)
		s_(a, 'a');
	else
		return ;
	position_next(a, b, order);
}

static void	quick_sort_a(t_list **a, t_list **b, t_order *order)
{
	int	i;
	int	count_b;

	i = -1;
	count_b = ft_lstsize(*b);
	while (ft_lstsize(*b) && ++i < count_b)
	{
		if ((*b)->index == order->next)
			position_next(a, b, order);
		else if ((*b)->index >= order->midium)
		{
			(*b)->flag = order->phase_flag;
			pa(a, b);
		}
		else if ((*b)->index < order->midium)
			r_(b, 'b');
	}
	track_order(order);
}

static void	quick_sort_b(t_list **a, t_list **b, t_order *order)
{
	int	phase_flag;

	phase_flag = (*a)->flag;
	if (phase_flag)
	{
		while ((*a)->flag == phase_flag)
		{
			if ((*a)->index != order->next)
				pb(b, a);
			position_next(a, b, order);
		}
	}
	else
	{
		while ((*a)->flag != -1)
		{
			if ((*a)->index != order->next)
				pb(b, a);
			position_next(a, b, order);
		}
	}
	if (ft_lstsize(*b))
		order->max = get_max_index(*b);
	order->midium = (order->max - order->next) / 2 + order->next;
}
