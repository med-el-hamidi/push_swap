#include "push_swap.h"

void print(t_stack *a, t_stack *b)
{
	printf("%34s	%34s\n", "_____", "_____");
	while (a || b)
	{
		if (a)
			printf("%11d %22d	", a->index, a->nbr);
		else
			printf("%11c %22c	", ' ', ' ');

		if (b)
			printf("%11d %22d", b->index, b->nbr);
		else
			printf("%11c %22c", ' ', ' ');
		printf("\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("%11s %22s	%11s %22s\n", "_____", "_____", "_____", "_____");
	printf("%11c %22c	%11c %22c\n", 'i', 'a', 'i', 'b');
	printf("\n\n\n");
}
