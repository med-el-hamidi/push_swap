#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //debug
# include "ft_printf.h"

# define EXIT_INVALID_INPUT 2

typedef struct s_order {
	int	next;
	int max;
	int	midium;
	int	flag;
}	t_order;

int		is_sorted(t_list *a);

int		swap(t_list **stack);
int		push(t_list **to, t_list **from);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **to_a, t_list **from_b);
void	pb(t_list **to_b, t_list **from_a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	_print(t_list *a, t_list *b);

void	stack_indexing(t_list *stack, int len);

void	ra_or_rra(t_list **a, int len, int *flag);


void	sort_three(t_list **stack_a);
void	sort_45(t_list **stack_a, t_list **stack_b, int len);
void	quick_sort(t_list **stack_a, t_list **stack_b, int len);

#endif
