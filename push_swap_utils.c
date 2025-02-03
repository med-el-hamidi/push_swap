#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

void	swap_(t_list **stack, char c)
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

int	push(t_list **to, t_list **from)
{
	t_list *ptr;

	if (!from || !*from)
		return (0);
	ptr = (*from)->next;
	(*from)->next = NULL;
	ft_lstadd_front(to, *from);
	*from = ptr;
	return (1);
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

void rotate(t_list **stack)
{
	t_list	*ptr;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	ptr = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = NULL;
	*stack = ptr;
}

void	rotate_(t_list **stack, char c)
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

void rrotate(t_list **stack)
{
	t_list	*ptr;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	ptr = *stack;
	while (ptr->next->next)
		ptr = ptr->next;
	ft_lstadd_front(stack, ptr->next);
	ptr->next = NULL;
}

void	rrotate_(t_list **stack, char c)
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
