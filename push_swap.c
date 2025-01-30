#include "push_swap.h"

static void	handle_input(int ac, char **av);
static void	handle_occurence(t_list *a);
//static void	sort_stack(t_list **a, t_list **b, int size_a, int size_b);
static void	sort_stack(t_list **a);
static void	error_msg(void );

static void	_f(void )
{
	system ("leaks push_swap");
}

void _print(t_list *a, t_list *b)
{
	printf("%11s	%11s\n", "_____", "_____");
	while (a || b)
	{
		if (a)
			printf("%11d	", a->nbr);
		else
			printf("%11c	", ' ');

		if (b)
			printf("%11d", b->nbr);
		else
			printf("%11c", ' ');
		printf("\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("%11s	%11s\n", "_____", "_____");
	printf("%11c	%11c\n", 'a', 'b');
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
	i = 0;
	a = ft_lstnew(atoi(argv[i + 1]));
	if (!a)
		return (EXIT_FAILURE);
	while (++i < argc-1)
	{
		node = ft_lstnew(atoi(argv[i + 1]));
		if (!node)
		{
			ft_lstclear(&a);
			return (EXIT_FAILURE);
		}
		ft_lstadd_back(&a, node);
	}
	handle_occurence(a);
	//sort_stack(&a, &b, argc-1, 0);
	if (!is_sorted(a))
		sort_stack(&a);
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
		else if (k == 11 && ((arg[0] == '+' && ft_strncmp(arg, "+2147483647", k) > 0)
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

static void sort_stack(t_list **a)
{
	t_list	*b;
	int		i;

	b = NULL;
	_print(*a, b);
	if (ft_lstsize(*a) == 2)
		sa(a);
	else
	{
		b = ft_sort_b(a);
		a = ft_sort_a(a, &b);
		i = ft_find_index(*a, ft_min(*a));
		if (i < ft_lstsize(*a) - i)
		{
			while ((*a)->nbr != ft_min(*a))
				ra(a);
		}
		else
		{
			while ((*a)->nbr != ft_min(*a))
				rra(a);
		}
	}
	_print(*a, b);
}

static void	error_msg(void )
{
	ft_printf("Error\n");
}
