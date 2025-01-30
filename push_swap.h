#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //debug
# include "ft_printf.h"

# define EXIT_INVALID_INPUT 2

int	is_sorted(t_list *a);

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

int			ft_min(t_list *a);
int			ft_max(t_list *a);
int			ft_find_index(t_list *a, int nbr);
int			ft_find_place_b(t_list *stack_b, int nbr_push);
int			ft_find_place_a(t_list *a, int nbr);
void		ft_sort_b_till_3(t_list **stack_a, t_list **stack_b);
t_list		*ft_sort_b(t_list **stack_a);
t_list		**ft_sort_a(t_list **stack_a, t_list **stack_b);
void		sort_three(t_list **stack_a, t_list **stack_b);

int			ft_case_rarb_a(t_list *a, t_list *b, int c);
int			ft_case_rrarrb_a(t_list *a, t_list *b, int c);
int			ft_case_rarrb_a(t_list *a, t_list *b, int c);
int			ft_case_rrarb_a(t_list *a, t_list *b, int c);
int			ft_case_rarb(t_list *a, t_list *b, int c);
int			ft_case_rrarrb(t_list *a, t_list *b, int c);
int			ft_case_rrarb(t_list *a, t_list *b, int c);
int			ft_case_rarrb(t_list *a, t_list *b, int c);
int			ft_rotate_type_ab(t_list *a, t_list *b);
int			ft_rotate_type_ba(t_list *a, t_list *b);
int			ft_apply_rarb(t_list **a, t_list **b, int c, char s);
int			ft_apply_rrarrb(t_list **a, t_list **b, int c, char s);
int			ft_apply_rrarb(t_list **a, t_list **b, int c, char s);
int			ft_apply_rarrb(t_list **a, t_list **b, int c, char s);
#endif
