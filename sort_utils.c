#include "push_swap.h"

int	is_sorted(t_list *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (min > a->nbr)
			return (0);
		min = a->nbr;
		a = a->next;
	}
	return (1);
}

void ra_or_rra(t_list **a, int len, int *flag)
{
	int		count;
	t_list	*tmp;

	if (len <= 5)
	{
		if (*flag == 1)
			rotate_(a, 'a');
		else if (*flag == -1)
			rrotate_(a, 'a');
		else
		{
			tmp = *a;
			count = 0;
			while (!(*flag) && tmp && tmp->index != 0)
			{
				count++;
				tmp = tmp->next;
			}
			while (*flag == 2 && tmp && tmp->index != 1)
			{
				count++;
				tmp = tmp->next;
			}
			if (!(*flag) && count <= (len - 3))
				*flag = 1;
			else if (*flag == 2 && count <= 2)
				*flag = 1;
			else
				*flag = -1;
			ra_or_rra(a, len, flag);
		}
	}
}
