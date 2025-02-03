#include "push_swap.h"

static char	*_three_sorted(t_list **stack_a);
static void	_sort_2b3a(t_list **stack_a, t_list **stack_b);

void	sort_three(t_list **stack_a)
{
	char *res;

	res = _three_sorted(stack_a);
	if (!ft_strncmp(res, "sa\nrra", 7))
	{
		swap_(stack_a, 'a');
		rrotate_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "sa", 3))
		swap_(stack_a, 'a');
	else if (!ft_strncmp(res, "ra", 3))
		rotate_(stack_a, 'a');
	else if (!ft_strncmp(res, "sa\nra", 6))
	{
		swap_(stack_a, 'a');
		rotate_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "rra", 4))
		rrotate_(stack_a, 'a');
	_print(*stack_a, NULL);
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
		if (f == (len - 3))
			break ;
		else if ((*stack_a)->index == 0 || (len == 5 && (*stack_a)->index == 1))
		{
			f++;
			f_ra_rra = 2;
			pb(stack_b, stack_a);
		}
		else
			ra_or_rra(stack_a, len, &f_ra_rra);
		_print(*stack_a, *stack_b);
	}
	if (len == 5 && (*stack_b)->nbr < (*stack_b)->next->nbr)
		_sort_2b3a(stack_a, stack_b);
	else
		sort_three(stack_a);
	while (f--)
		pa(stack_a, stack_b);
	_print(*stack_a, *stack_b);
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
	char *res;

	res = _three_sorted(stack_a);
	if (!ft_strncmp(res, "sa\nrra", 7))
	{
		ss(stack_a, stack_b);
		rrotate_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "sa", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(res, "ra", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(res, "sa\nra", 6))
	{
		ss(stack_a, stack_b);
		rotate_(stack_a, 'a');
	}
	else if (!ft_strncmp(res, "rra", 4))
		rrr(stack_a, stack_b);
}
