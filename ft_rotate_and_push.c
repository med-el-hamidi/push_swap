#include "push_swap.h"

// This function rotates both stack_a and stack_b
// in the same direction as required amount.
int	ft_apply_rarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			rr(a, b);
		while ((*a)->nbr != c)
			ra(a);
		while (ft_find_place_b(*b, c) > 0)
			rb(b);
		pb(b , a);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			rr(a, b);
		while ((*b)->nbr != c)
			rb(b);
		while (ft_find_place_a(*a, c) > 0)
			ra(a);
		pb(b , a);
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
int	ft_apply_rrarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			rrr(a, b);
		while ((*a)->nbr != c)
			rra(a);
		while (ft_find_place_b(*b, c) > 0)
			rrb(b);
		pb(b, a);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			rrr(a, b);
		while ((*b)->nbr != c)
			rrb(b);
		while (ft_find_place_a(*a, c) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
int	ft_apply_rrarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			rra(a);
		while (ft_find_place_b(*b, c) > 0)
			rb(b);
		pb(b, a);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			rra(a);
		while ((*b)->nbr != c)
			rb(b);
		pa(a, b);
	}
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
int	ft_apply_rarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ra(a);
		while (ft_find_place_b(*b, c) > 0)
			rrb(b);
		pb(b, a);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ra(a);
		while ((*b)->nbr != c)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}
