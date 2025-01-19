#include "push_swap.h"

void swap(int **stack, int len)
{
	int tmp;

	if (len <= 1)
		return ;
	tmp = *stack[0];
	*stack[0] = *stack[1];
	*stack[1] = tmp;
}

void push(int **to, int **from, int len)
{
	while (len-- > 1)
		*to[len] = *to[len - 1];
	*to[0] = *from[0];
}
