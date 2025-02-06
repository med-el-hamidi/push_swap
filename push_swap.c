#include "push_swap.h"

static void	_fill_stack(t_list **a, char **argv, int ac, int ac_changed);
static void	_sort_stack(t_list **a, int len);

// static void	_f(void )
// {
// 	system ("leaks push_swap");
// }

int	main(int ac, char **av)
{
	t_list	*a;
	char	**argv;
	int		old_ac;

	if (ac < 2)
		return (EXIT_INVALID_INPUT);
	old_ac = ac;
	argv = handle_input(&ac, av);
	if (old_ac != ac && ac == 1)
	{
		free_argv(argv);
		return (EXIT_SUCCESS);
	}
	a = NULL;
	_fill_stack(&a, argv, ac, old_ac);
	if (old_ac != ac || ac == 2)
		free_argv(argv);
	else
		ac--;
	handle_occurence(a);
	if (is_sorted(a))
		return (EXIT_SUCCESS);
	stack_indexing(a, ac);
	_sort_stack(&a, ac);
	ft_lstclear(&a);
	//atexit(_f);
	return (EXIT_SUCCESS);
}

static void	_fill_stack(t_list **a, char **argv, int ac, int ac_changed)
{
	t_list	*node;
	int		i;

	if (ac_changed || (!ac_changed && ac == 2))
		i = -1;
	else
		i = 0;
	while (++i < ac)
	{
		node = ft_lstnew(atoi(argv[i]));
		if (!node)
		{
			ft_lstclear(a);
			free_exit(EXIT_FAILURE, argv, ac_changed);
		}
		node->index = -1;
		ft_lstadd_back(a, node);
	}
}

static void _sort_stack(t_list **a, int len)
{
	t_list	*b;

	b = NULL;
	//_print(*a, b);
	if (len == 2)
		s_(a, 'a');
	else if (len == 3)
		sort_three(a);
	else if (len <= 5)
		sort_4nd5(a, &b, len);
	else
		quick_sort(a, &b, len);
	//_print(*a, b);
}

void _print(t_list *a, t_list *b)
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
