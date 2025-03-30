#include "push_swap.h"

static void	insert_index(t_stack *stack, int min, int i)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->nbr == min)
			break ;
		tmp = tmp->next;
	}
	tmp->index = i;
}

static int	get_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

void	stack_indexing(t_stack *stack, int ac)
{
	int	next_min;
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (i < ac)
	{
		next_min = get_min(stack);
		insert_index(stack, next_min, i);
		i++;
	}
}
