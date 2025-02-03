#include "push_swap.h"

static void	insert_index(t_list *stack, int min, int i);
static int	get_min(t_list *stack);

void	stack_indexing(t_list *stack, int len)
{
	int	next_min;
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (i < len)
	{
		next_min = get_min(stack);
		insert_index(stack, next_min, i);
		i++;
	}
}

static void	insert_index(t_list *stack, int min, int i)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->nbr == min)
			break ;
		tmp = tmp->next;
	}
	tmp->index = i;
}

static int	get_min(t_list *stack)
{
	t_list	*tmp;
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
