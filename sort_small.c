#include "push_swap.h"

static char	*_three_sorted(t_list **stack_a);
static void	_sort_2b3a(t_list **stack_a, t_list **stack_b);

void	sort_three(t_list **stack_a)
{
	char	*res;

	res = _three_sorted(stack_a);
	if (!res)
		return ;
	if (!ft_strncmp(res, "sa\nrra", 7))
	{
		s_(stack_a, 'a');
		rr_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "sa", 3))
		s_(stack_a, 'a');
	else if (!ft_strncmp(res, "ra", 3))
		r_(stack_a, 'a');
	else if (!ft_strncmp(res, "sa\nra", 6))
	{
		s_(stack_a, 'a');
		r_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "rra", 4))
		rr_(stack_a, 'a');
}

void	sort_4nd5(t_list **stack_a, t_list **stack_b, int len)
{
	int		i;
	int		flag;
	int		f;

	i = -1;
	flag = 0;
	f = 0;
	while (++i < len)
	{
		if ((*stack_a)->index == 0 || (len == 5 && (*stack_a)->index == 1))
		{
			f = 2;
			pb(stack_b, stack_a);
			if (++flag == (len - 3))
				break ;
		}
		else
			ra_or_rra(stack_a, len, &f);
	}
	if (len == 5 && (*stack_b)->nbr < (*stack_b)->next->nbr)
		_sort_2b3a(stack_a, stack_b);
	else if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (flag--)
		pa(stack_a, stack_b);
}

static char	*_three_sorted(t_list **stack_a)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if (!last)
		return (NULL);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr > last->nbr)
		return ("sa\nrra");
	else if ((*stack_a)->nbr < last->nbr
		&& (*stack_a)->next->nbr < last->nbr)
		return ("sa");
	else if ((*stack_a)->nbr > last->nbr
		&& (*stack_a)->next->nbr < last->nbr)
		return ("ra");
	else if ((*stack_a)->nbr < last->nbr
		&& (*stack_a)->next->nbr > last->nbr)
		return ("sa\nra");
	else if ((*stack_a)->nbr > last->nbr
		&& (*stack_a)->next->nbr > last->nbr)
		return ("rra");
	return (NULL);
}

static void	_sort_2b3a(t_list **stack_a, t_list **stack_b)
{
	char	*res;

	res = NULL;
	if (!is_sorted(*stack_a))
		res = _three_sorted(stack_a);
	if (!res)
		s_(stack_b, 'b');
	else if (!ft_strncmp(res, "sa\nrra", 7))
	{
		ss(stack_a, stack_b);
		rr_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "sa", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(res, "ra", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(res, "sa\nra", 6))
	{
		ss(stack_a, stack_b);
		r_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "rra", 4))
		rrr(stack_a, stack_b);
}
