#include "checker_bonus.h"

static void	_action(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "pa\n", 3))
		push(a, b);
	else if (!ft_strncmp(move, "pb\n", 3))
		push(b, a);
	else if (!ft_strncmp(move, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(move, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(move, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(move, "rra\n", 4))
		rrotate(a);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrotate(b);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(a, b);
}

static int	_check_order(t_stack **a, t_instruct *ins)
{
	t_stack		*b;
	t_instruct	*ptr;

	b = NULL;
	ptr = ins;
	while (ptr)
	{
		_action(a, &b, ptr->str);
		ptr = ptr->next;
	}
	if (b)
	{
		ft_lstclear(&b);
		return (0);
	}
	return (is_sorted(*a));
}

void	output(t_stack **a, t_instruct *ins)
{
	if (_check_order(a, ins))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
