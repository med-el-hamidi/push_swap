#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr > last->nbr)
	{
		sa(&*stack_a);
		rra(&*stack_a);
	}
	else if ((*stack_a)->nbr < last->nbr
		&& (*stack_a)->next->nbr < last->nbr)
		sa(stack_a);
	else if ((*stack_a)->nbr > last->nbr
		&& (*stack_a)->next->nbr < last->nbr)
		ra(stack_a);
	else if ((*stack_a)->nbr < last->nbr
		&& (*stack_a)->next->nbr > last->nbr)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->nbr > last->nbr
		&& (*stack_a)->next->nbr > last->nbr)
		rra(stack_a);
	_print(*stack_a, NULL);
}

void	sort_45(t_list **stack_a, t_list **stack_b, int len)
{
	int i;
	int	f;
	int f_ra_rra;

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
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (len == 5)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
	}
	_print(*stack_a, *stack_b);
}
