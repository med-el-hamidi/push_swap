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

void	sa(t_list **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_list **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	if (swap(a) && swap(b))
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

void	ra(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
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

void	rra(t_list **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
