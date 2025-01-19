#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //debug
# include "ft_printf.h"

# define EXIT_INVALID_INPUT 2

void swap(int **stack, int len);
void push(int **a, int **b, int len);
#endif
