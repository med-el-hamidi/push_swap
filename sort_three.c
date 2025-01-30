#include "push_swap.h"

static char	*sort_three_a(t_list **a);
static char	*sort_three_b(t_list **b);

void	sort_three(t_list **a, t_list **b)
{
	char *op_a;
	char *op_b;
	int		size_a;
	int		size_b;

	op_a = sort_three_a(a);
	op_b = sort_three_b(b);
	size_a = ft_strlen(op_a);
	size_b = 0;
	if (op_b)
		size_b = ft_strlen(op_b);
	if (!ft_strncmp(op_a, "sa", size_a) && op_b && !ft_strncmp(op_b, "sb", size_b))
		ss(a, b);
	else if (!ft_strncmp(op_a, "sa", size_a))
		sa(a);
	else if (op_b && !ft_strncmp(op_b, "sb", size_b))
		sb(b);
	if (!ft_strncmp(op_a, "sa\nrra", size_a) && op_b && !ft_strncmp(op_b, "sb\nrrb", size_b))
	{
		ss(a, b);
		rrr(a, b);
	}
	else if (!ft_strncmp(op_a, "sa\nrra", size_a))
	{
		sa(a);
		rra(a);
	}
	else if (op_b && !ft_strncmp(op_b, "sb\nrrb", size_b))
	{
		sb(b);
		rrb(b);
	}
	if (!ft_strncmp(op_a, "ra", size_a) && op_b && !ft_strncmp(op_b, "rb", size_b))
		rr(a, b);
	else if (!ft_strncmp(op_a, "ra", size_a))
		ra(a);
	else if (op_b && !ft_strncmp(op_b, "rb", size_b))
		rb(b);
	if (!ft_strncmp(op_a, "sa\nra", size_a) && op_b && !ft_strncmp(op_b, "sb\nrb", size_b))
	{
		ss(a, b);
		rr(a, b);
	}
	else if (!ft_strncmp(op_a, "sa\nra", size_a))
	{
		sa(a);
		ra(a);
	}
	else if (op_b && !ft_strncmp(op_b, "sb\nrb", size_b))
	{
		sb(b);
		rb(b);
	}
	if (!ft_strncmp(op_a, "rra", size_a) && op_b && !ft_strncmp(op_b, "rrb", size_b))
		rrr(a, b);
	else if (!ft_strncmp(op_a, "rra", size_a))
		rra(a);
	else if (op_b && !ft_strncmp(op_b, "rrb", size_b))
		rrb(b);
}

static char	*sort_three_a(t_list **a)
{
	int	top;
	int	mid;
	int	bottom;

	if (!a || ft_lstsize(*a) != 3)
		return (0);
	top = (*a)->nbr;
	mid = (*a)->next->nbr;
	bottom = (*a)->next->next->nbr;
	if (top > mid && mid < bottom && top < bottom)
		return ("sa"); // Case: 2 1 3 -> 1 2 3
	else if (top > mid && mid > bottom)
		return ("sa\nrra"); // Case: 3 2 1 -> 2 3 1
	else if (top > mid && mid < bottom && top > bottom)
		return ("ra"); // Case: 3 1 2 -> 1 2 3
	else if (top < mid && mid > bottom && top < bottom)
		return ("sa\nra"); // Case: 1 3 2 -> 3 1 2
	else if (top < mid && mid > bottom && top > bottom)
		return ("rra"); // Case: 2 3 1 -> 1 2 3
	return (0);
}

static char	*sort_three_b(t_list **b)
{
	int	top;
	int	mid;
	int	bottom;

	if (!b)
		return (0);
	top = (*b)->nbr;
	mid = (*b)->next->nbr;
	bottom = (*b)->next->next->nbr;
	if (top > mid && mid < bottom && top < bottom)
		return ("sb"); // Case: 2 1 3 -> 1 2 3
	else if (top > mid && mid > bottom)
		return ("sb\nrrb"); // Case: 3 2 1 -> 2 3 1
	else if (top > mid && mid < bottom && top > bottom)
		return ("rb"); // Case: 3 1 2 -> 1 2 3
	else if (top < mid && mid > bottom && top < bottom)
		return ("sb\nrb"); // Case: 1 3 2 -> 3 1 2
	else if (top < mid && mid > bottom && top > bottom)
		return ("rrb"); // Case: 2 3 1 -> 1 2 3
	return (0);
}
