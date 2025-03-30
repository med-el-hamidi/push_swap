#include "push_swap.h"

static char	*_three_sorted(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack_a;
	second = first->next;
	third = second->next;
	if (first->nbr > second->nbr && first->nbr > third->nbr)
	{
		if (second->nbr < third->nbr)
			return ("ra");
		else
			return ("sa\nrra");
	}
	else if (second->nbr > first->nbr && second->nbr > third->nbr)
	{
		if (first->nbr < third->nbr)
			return ("sa\nra");
		else
			return ("rra");
	}
	else if (first->nbr > second->nbr)
		return ("sa");
	return (NULL);
}

void	sort_three(t_stack **stack_a)
{
	char	*res;

	res = _three_sorted(stack_a);
	if (!res)
		return ;
	if (!ft_strncmp(res, "ra", 3))
		r_(stack_a, 'a');
	else if (!ft_strncmp(res, "sa\nrra", 7))
	{
		s_(stack_a, 'a');
		rr_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "sa\nra", 6))
	{
		s_(stack_a, 'a');
		r_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "rra", 4))
		rr_(stack_a, 'a');
	else if (!ft_strncmp(res, "sa", 3))
		s_(stack_a, 'a');
}

static void	_sort_2b3a(t_stack **stack_a, t_stack **stack_b)
{
	char	*res;

	res = NULL;
	if (!is_sorted(*stack_a))
		res = _three_sorted(stack_a);
	if (!res)
		s_(stack_b, 'b');
	else if (!ft_strncmp(res, "ra", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(res, "sa\nrra", 7))
	{
		ss(stack_a, stack_b);
		rr_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "sa\nra", 6))
	{
		ss(stack_a, stack_b);
		r_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "rra", 4))
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(res, "sa", 3))
		ss(stack_a, stack_b);
}

void	sort_4nd5(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	int		flag;
	int		f;

	i = -1;
	flag = 0;
	f = 0;
	while (++i < size)
	{
		if ((*stack_a)->index == 0 || (size == 5 && (*stack_a)->index == 1))
		{
			f = 2;
			pb(stack_b, stack_a);
			if (++flag == (size - 3))
				break ;
		}
		else
			ra_or_rra(stack_a, size, &f);
	}
	if (size == 5 && (*stack_b)->nbr < (*stack_b)->next->nbr)
		_sort_2b3a(stack_a, stack_b);
	else if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (flag--)
		pa(stack_a, stack_b);
}
