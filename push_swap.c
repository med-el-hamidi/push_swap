#include "push_swap.h"

static void	handle_input(int ac, char **av);
static void	error_msg(void );
static void	handle_occurence(int *a, int len);

static void	_f(void )
{
	system ("leaks a.out");
}

static void _print(int *a, int *b, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		printf("%11d	%11d\n", a[i], b[i]);
	printf("%11s	%11s\n", "_____", "_____");
	printf("%11c	%11c\n", 'a', 'b');
	printf("\n\n\n");
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	i;

	if (argc < 2)
		return (EXIT_INVALID_INPUT);
	handle_input(argc, argv);
	a = malloc((argc-1) * sizeof(int));
	if (!a)
		return (EXIT_FAILURE);
	i = 0;
	while (i < argc-1)
	{
		a[i] = atoi(argv[i + 1]);
		i++;
	}
	_print(a, a, argc-1);
	handle_occurence(a, argc-1);
	b = malloc((argc-1) * sizeof(int));
	if (!b)
		return (EXIT_FAILURE);
	_print(a, b, argc-1);

	swap(&a, argc-1);
	_print(a, b, argc-1);

	push(&b, &a, argc-1);
	_print(a, b, argc-1);

	free(a);
	free(b);
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

static void	handle_occurence(int *a, int len)
{
	int	i;
	int	k;

	i = 0;
	while (i < len)
	{
		k = 0;
		while ((++k + i) < len)
		{
			if (a[i] == a[i + k])
			{
				free(a);
				error_msg();
				exit (EXIT_INVALID_INPUT);
			}
		}
		i++;
	}
}

static void	error_msg(void )
{
	ft_printf("Error\n");
}
