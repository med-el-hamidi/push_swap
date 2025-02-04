#include "push_swap.h"

void	s_(t_list **stack, char c)
{
	if (swap(stack))
		ft_printf("s%c\n", c);
}

void	ss(t_list **a, t_list **b)
{
	if (!a || !*a || !(*a)->next
		|| !b || !*b || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	pa(t_list **to_a, t_list **from_b)
{
	if (push(to_a, from_b))
		ft_printf("pa\n");
}

void	pb(t_list **to_b, t_list **from_a)
{
	if (push(to_b, from_a))
		ft_printf("pb\n");
}
