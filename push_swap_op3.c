#include "push_swap.h"

void	r_(t_list **stack, char c)
{
	rotate(stack);
	ft_printf("r%c\n", c);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rr_(t_list **stack, char c)
{
	rrotate(stack);
	ft_printf("rr%c\n", c);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
