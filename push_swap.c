#include "push_swap.h"

static void	_fill_stack(t_stack **a, char ***argv);
static void	_push_swap(t_stack **a, int size);

int	main(int ac, char **av)
{
	t_stack	*a;
	char	***argv;

	if (ac < 2)
		return (EXIT_INVALID_INPUT);
	argv = handle_input(&ac, av);
	if (ac == 1)
		free_exit(EXIT_SUCCESS, argv);
	a = NULL;
	_fill_stack(&a, argv);
	handle_occurence(a);
	if (is_sorted(a))
		return (EXIT_SUCCESS);
	stack_indexing(a, ac);
	_push_swap(&a, ac);
	return (EXIT_SUCCESS);
}

static void	_fill_stack(t_stack **a, char ***argv)
{
	t_stack	*node;
	int		i;
	int		j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			node = ft_lstnew(atoi(argv[i][j++]));
			if (!node)
			{
				ft_lstclear(a);
				free_exit(EXIT_FAILURE, argv);
			}
			node->index = -1;
			ft_lstadd_back(a, node);
		}
	}
	free_argv(argv);
}

static void _push_swap(t_stack **a, int size)
{
	t_stack	*b;

	b = NULL;
	if (size == 2)
		s_(a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_4nd5(a, &b, size);
	else
	 	quick_sort(a, &b, size);
	ft_lstclear(a);
}

