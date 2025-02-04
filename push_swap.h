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
	int	phase_flag;
}	t_order;

void	_print(t_list *a, t_list *b);
int		is_sorted(t_list *a);

int		swap(t_list **stack);
int		push(t_list **to, t_list **from);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);

void	s_(t_list **stack, char c);
void	ss(t_list **a, t_list **b);
void	pa(t_list **to_a, t_list **from_b);
void	pb(t_list **to_b, t_list **from_a);
void	r_(t_list **stack, char c);
void	rr(t_list **a, t_list **b);
void	rr_(t_list **stack, char c);
void	rrr(t_list **a, t_list **b);

void	stack_indexing(t_list *stack, int len);
void	ra_or_rra(t_list **a, int len, int *flag);

void	sort_three(t_list **stack_a);
void	sort_4nd5(t_list **stack_a, t_list **stack_b, int len);
void	sort_six(t_list **stack_a, t_list **stack_b);
void	quick_sort(t_list **stack_a, t_list **stack_b, int len);

int		get_max_index(t_list *stack);
void	track_order(t_order *order);
#endif
