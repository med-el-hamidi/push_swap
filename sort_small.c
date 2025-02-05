#include "push_swap.h"

static char	*_three_sorted(t_list **stack_a);
static void	_sort_2b3a(t_list **stack_a, t_list **stack_b);

void	sort_three(t_list **stack_a)
{
	char	*res;

	res = _three_sorted(stack_a);
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
	int		f;
	int		f_ra_rra;

	i = -1;
	f = 0;
	f_ra_rra = 0;
	while (++i < len)
	{
		if ((*stack_a)->index == 0 || (len == 5 && (*stack_a)->index == 1))
		{
			f_ra_rra = 2;
			pb(stack_b, stack_a);
			if (++f == (len - 3))
				break ;
		}
		else
			ra_or_rra(stack_a, len, &f_ra_rra);
	}
	if (len == 5 && (*stack_b)->nbr < (*stack_b)->next->nbr)
		_sort_2b3a(stack_a, stack_b);
	else
		sort_three(stack_a);
	while (f--)
		pa(stack_a, stack_b);
}

void	sort_six(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		f;
	int		f_ra_rra;

	i = -1;
	f = 0;
	f_ra_rra = 0;
	while (++i < 6)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1 || (*stack_a)->index == 2)
		{
			f_ra_rra = 2;
			pb(stack_b, stack_a);
			if (++f == 3)
				break ;
		}
		else
			ra_or_rra(stack_a, 6, &f_ra_rra);
	}
	sort_three(stack_a);
	sort_three(stack_a);
	while (f--)
		pa(stack_a, stack_b);
}

static char	*_three_sorted(t_list **stack_a)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
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

	res = _three_sorted(stack_a);
	if (!ft_strncmp(res, "sa\nrra", 7))
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
