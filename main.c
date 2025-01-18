#include "push_swap.h"

static void	handle_input(int ac, char **av);
static void	error_msg(void );

static void _f(void )
{
	system ("leaks a.out");
}

static void _print(int *a, int len)
{
	int	i;

	i = 0;
	while (++i < len)
		printf("->%s\n", a);
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	i;

	if (argc < 2)
		return (SIG_INVALID_INPUT);

	handle_input(argc, argv);
	//ft_printf("Yey\n");
	a = malloc((argc - 1) * sizeof(int));
	if (!a)
		return (SIG_ERROR);
	i = 0;
	while (++i < argc)
		a[i] = atoi(argv[i]);
	_print(a, argc);
	free(a);
	atexit(_f);
	return (0);
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
				exit (SIG_INVALID_INPUT);
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
		if (k == 1 && (arg[0] == '+' || arg[0] == '-'))
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
			exit (SIG_INVALID_INPUT);
		}
	}
}

static void	error_msg(void )
{
	ft_printf("Error\n");
}
