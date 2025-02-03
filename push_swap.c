#include "push_swap.h"

static void	handle_input(int ac, char **av);
static void	handle_occurence(t_list *a);
static void	sort_stack(t_list **a, int len);
static void	error_msg(void );

static void	_f(void )
{
	system ("leaks push_swap");
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

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*node;
	int	i;

	if (argc < 2)
		return (EXIT_INVALID_INPUT);
	handle_input(argc, argv);
	if (argc == 2)
		return (EXIT_SUCCESS);
	a = NULL;
	i = -1;
	while (++i < argc-1)
	{
		node = ft_lstnew(atoi(argv[i + 1]));
		if (!node)
		{
			ft_lstclear(&a);
			error_msg();
			return (EXIT_FAILURE);
		}
		node->index = -1;
		ft_lstadd_back(&a, node);
	}
	handle_occurence(a);
	_print(a, NULL);
	if (is_sorted(a))
		return (EXIT_SUCCESS);
	stack_indexing(a, argc - 1);
	sort_stack(&a, argc - 1);
	ft_lstclear(&a);
	atexit(_f);
	return (EXIT_SUCCESS);
}

static void	handle_input(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	int		flag;
	char	arg[12];
	int		is_int;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		k = 0;
		flag = 0;
		ft_bzero(arg, 12);
		if (av[i][j] == '-' || av[i][j] == '+')
			arg[k++] = av[i][j++];
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				error_msg();
				exit (EXIT_INVALID_INPUT);
			}
			if (!flag && av[i][j] != '0')
				flag = 1;
			if (flag)
			{
				arg[k++] = av[i][j];
				if (k > 11)
					break ;
			}
			j++;
		}
		if (!flag && av[i][j - 1] == '0')
			is_int = 1;
		else if (k == 1 && (arg[0] == '+' || arg[0] == '-'))
			is_int = 0;
		else if (k > 11)
			is_int = 0;
		else if (k == 11 && ( ft_isdigit(arg[0])
				|| (arg[0] == '+' && ft_strncmp(arg, "+2147483647", k) > 0)
				|| (arg[0] == '-' && ft_strncmp(arg, "-2147483648", k) > 0)))
			is_int = 0;
		else if (k == 10 && ft_strncmp(arg, "2147483647", k) > 0)
			is_int = 0;
		else
			is_int = 1;
		if (!is_int)
		{
			error_msg();
			exit (EXIT_INVALID_INPUT);
		}
	}
}

static void	handle_occurence(t_list *a)
{
	t_list	*ptr;
	t_list	*ptr_k;

	ptr = a;
	while (ptr)
	{
		ptr_k = ptr->next;
		while (ptr_k)
		{
			if (ptr->nbr == ptr_k->nbr)
			{
				ft_lstclear(&a);
				error_msg();
				exit (EXIT_INVALID_INPUT);
			}
			ptr_k = ptr_k->next;
		}
		ptr = ptr->next;
	}
}

static void sort_stack(t_list **a, int len)
{
	t_list	*b;

	b = NULL;
	_print(*a, b);
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else if (len <= 5)
		sort_45(a, &b, len);
	else
		quick_sort(a, &b, len);
	_print(*a, b);
}

static void	error_msg(void )
{
	ft_printf("Error\n");
}
