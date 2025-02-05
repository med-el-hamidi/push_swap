#include "push_swap.h"

static int	count_till_0or1_index(t_list *a, int len);

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

void	ra_or_rra(t_list **a, int len, int *flag)
{
	int		count;
	t_list	*ptr;

	if (*flag == 1)
		r_(a, 'a');
	else if (*flag == -1)
		rr_(a, 'a');
	else
	{
		ptr = *a;
		count = count_till_0or1_index(ptr, len);
		if (!(*flag) && count <= 1)
			*flag = 1;
		else if (*flag == 2 && count <= 2)
			*flag = 1;
		else
			*flag = -1;
		ra_or_rra(a, len, flag);
	}
}

static int	count_till_0or1_index(t_list *a, int len)
{
	int	count;

	count = 0;

	if (len == 4)
	{
		while (a && a->index != 0)
		{
			count++;
			a = a->next;
		}
	}
	else if (len == 5)
	{
		while (a && a->index != 0 && a->index != 1)
		{
			count++;
			a = a->next;
		}
	}
	return (count);
}
