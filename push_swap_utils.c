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

// void push_all_but_three(t_list **a, t_list **b)
// {
// 	int size;

// 	size = ft_lstsize(*a);
//     while (size > 3)
// 	{
// 		do_push(b, a, "pb"); // Push from a to b
//         size--;
//     }
// }

// void find_min_and_push(t_list **a, t_list **b)
// {
// 	int min_b;
// 	int position;

// 	min_b = find_min(*b); // Find the smallest element in stack b
// 	position = find_position(*b, min_b); // Find its position in stack b

//     // Rotate stack b to bring the smallest element to the top
// 	if (position <= ft_lstsize(*b) / 2)
// 	{
// 		while ((*b)->nbr != min_b)
// 		{
// 			do_rotate(b, "rb"); // Rotate b forward
// 		}
// 	}
// 	else
// 	{
// 		while ((*b)->nbr != min_b)
// 		{
// 			do_rrotate(b, "rrb"); // Rotate b backward
// 		}
// 	}

//     // Push the smallest element to stack a
// 	do_push(a, b, "pa");

//     // Rotate stack a to place the element in the correct position
// 	if ((*a)->next && (*a)->nbr > (*a)->next->nbr)
// 	{
// 		do_swap(a, "sa"); // Swap if necessary
// 	}
// }

// void rotate_to_min(t_list **a)
// {
// 	int min_a;
//     int position;

// 	min_a = find_min(*a); // Find the smallest element in stack a
// 	position = find_position(*a, min_a); // Find its position in stack a

//     // Rotate stack a to bring the smallest element to the top
// 	if (position <= ft_lstsize(*a) / 2)
// 	{
// 		while ((*a)->nbr != min_a)
// 		{
// 			do_rotate(a, "ra"); // Rotate a forward
// 		}
// 	}
// 	else
// 	{
// 		while ((*a)->nbr != min_a)
// 		{
// 			do_rrotate(a, "rra"); // Rotate a backward
// 		}
// 	}
// }

// int	find_position(t_list *stack, int value)
// {
// 	int position;

// 	position = 0;
// 	while (stack)
// 	{
// 		if (stack->nbr == value)
// 			return (position);
// 		stack = stack->next;
// 		position++;
// 	}
// 	return (-1); // Not found
// }

// int	find_min(t_list *stack)
// {
// 	int min;

// 	min = stack->nbr;
// 	while (stack)
// 	{
// 		if (stack->nbr < min)
// 			min = stack->nbr;
//         stack = stack->next;
//     }
//     return (min);
// }
