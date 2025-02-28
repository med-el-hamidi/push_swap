/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:36:08 by mel-hami          #+#    #+#             */
/*   Updated: 2025/02/27 12:36:09 by mel-hami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

# define EXIT_INVALID_INPUT 2
# define EXIT_NOT_INT 4
# define EXIT_OCCURENCE 11

void	_print(t_stack *a, t_stack *b);

void	free_argv(char ***argv);
void	free_exit(int e, char ***argv);

char	***handle_input(int *ac, char **av);
void	handle_occurence(t_stack *a);
int		is_sorted(t_stack *a);

int		swap(t_stack **stack);
int		push(t_stack **to, t_stack **from);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

void	s_(t_stack **stack, char c);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **to_a, t_stack **from_b);
void	pb(t_stack **to_b, t_stack **from_a);
void	r_(t_stack **stack, char c);
void	rr(t_stack **a, t_stack **b);
void	rr_(t_stack **stack, char c);
void	rrr(t_stack **a, t_stack **b);

void	stack_indexing(t_stack *stack, int ac);
void	ra_or_rra(t_stack **a, int ac, int *flag);

void	sort_three(t_stack **stack_a);
void	sort_4nd5(t_stack **stack_a, t_stack **stack_b, int ac);
void	quick_sort(t_stack **stack_a, t_stack **stack_b, int ac);

int		find_pos_of_max(t_stack *stack);
#endif
