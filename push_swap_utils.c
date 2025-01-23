#include "push_swap.h"

int	swap(t_list **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	return (1);
}

void	do_swap(t_list **stack, char *action)
{
	if (swap(stack))
		ft_printf("%s", action);
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

void	do_push(t_list **to, t_list **from, char *action)
{
	if (push(to, from))
		ft_printf("%s\n", action);
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

void	do_rotate(t_list **stack, char *action)
{
	rotate(stack);
	ft_printf("%s", action);
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

void	do_rrotate(t_list **stack, char *action)
{
	rrotate(stack);
	ft_printf("%s", action);
}
