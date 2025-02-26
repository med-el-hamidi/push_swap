#include "push_swap.h"

void	r_(t_stack **stack, char c)
{
	rotate(stack);
	ft_printf("r%c\n", c);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rr_(t_stack **stack, char c)
{
	rrotate(stack);
	ft_printf("rr%c\n", c);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
