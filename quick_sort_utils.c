#include "push_swap.h"

//static void _count_ra(int *count, int index, int mid, int *flag);
//static int	_count_rra(int *count, t_list *ptr, int mid, int *flag);

void	track_order(t_order *order)
{
	order->max = order->midium;
	order->midium = (order->max - order->next) / 2 + order->next;
	order->phase_flag++;
}

int	get_max_index(t_list *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

//int	*part_by_ra_or_rra(t_list *a, int len)
// {
// 	int		*result;
// 	int		mid;
// 	t_list	*ptr;
// 	int		count_ra;
// 	int		count_rra;
// 	int		i;
// 	int		flag_ra;
// 	int		flag_rra;

// 	ptr = a;
// 	count_ra = 0;
// 	count_rra = 0;
// 	i = -1;
// 	flag_ra = 0;
// 	flag_rra = 0;
// 	mid = (len - i) / 2 - 1;
// 	result = malloc(len * sizeof(int));
// 	if (!result)
// 		return (NULL);
// 	while (ptr && ++i < len)
// 	{
// 		if (i <= mid)
// 			_count_ra(&count_ra, a->index, mid, &flag_ra);
// 		else
// 		{
// 			if (_count_rra(&count_rra, ptr, mid, &flag_rra))
// 				break ;
// 		}
// 		if (count_ra > (mid - count_rra))
// 			result[i] = 1;
// 		else
// 			result[i] = 0;
// 		ptr = ptr->next;
// 	}
// 	return (result);
// }

//static void _count_ra(int *count, int index, int mid, int *flag)
// {
// 	if (!*flag && index <= mid)
// 	{
// 		++(*count);
// 		*flag = 1;
// 	}
// 	if (!*flag)
// 		(*count)++;
// }

//static int _count_rra(int *count, t_list *ptr, int mid, int *flag)
// {
// 	t_list *tmp_ptr;

// 	if (!*flag && ptr->index <= mid)
// 		*flag = 1;
// 	if (!*flag)
// 		count++;
// 	else
// 	{
// 		++count;
// 		tmp_ptr = ptr;
// 		while (tmp_ptr)
// 		{
// 			if (tmp_ptr->index <= mid)
// 			{
// 				*flag = 0;
// 				break ;
// 			}
// 			tmp_ptr = tmp_ptr->next;
// 		}
// 		if (*flag)
// 			return (1);
// 	}
// 	return (0);
// }
