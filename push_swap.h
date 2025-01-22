#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //debug
# include "ft_printf.h"

# define EXIT_INVALID_INPUT 2

int	swap(t_list **stack);
int	push(t_list **to, t_list **from);
void rotate(t_list **stack);
void rrotate(t_list **stack);
void operations(t_list **a, t_list **b, int min_idx, int *size);
void _print(t_list *a, t_list *b);
#endif
