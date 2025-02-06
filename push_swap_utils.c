#include "push_swap.h"

static char	**_handle_one_input(int *ac, char **av, int *ac_changed);
static int	_parse_argument(char **av, int i, char *arg, int ac_changed);
static int	_is_int(char *arg, int k);

char	**handle_input(int *ac, char **av)
{
	int		i;
	int		k;
	char	arg[12];
	char	**argv;
	int		ac_changed;

	i = 0;
	ac_changed = 0;
	argv = _handle_one_input(ac, av, &ac_changed);
	if (ac_changed)
		--i;
	while (++i < *ac)
	{
		ft_bzero(arg, 12);
		k = _parse_argument(argv, i, arg, ac_changed);
		if(!_is_int(arg, k))
			free_exit(EXIT_INVALID_INPUT, argv, ac_changed);
	}
	return (argv);
}

void	handle_occurence(t_list *a)
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
				error_exit(EXIT_INVALID_INPUT);
			}
			ptr_k = ptr_k->next;
		}
		ptr = ptr->next;
	}
}

static char	**_handle_one_input(int *ac, char **av, int *ac_changed)
{
	char	**argv;
	int		argc;

	argc = 0;
	if (*ac == 2)
	{
		argv = ft_split(av[1], ' ');
		if (!argv)
			error_exit(EXIT_FAILURE);
		*ac_changed = 1;
		while(argv[argc])
			argc++;
		if (argc == 0)
			free_exit(EXIT_INVALID_INPUT, argv, *ac_changed);
		*ac = argc;
	}
	else
		argv = av;
	return (argv);
}

static int _parse_argument(char **av, int i, char *arg, int ac_changed)
{
	int	j;
	int	k;
	int flag;

	j = 0;
	k = 0;
	flag = 0;
	if (av[i][j] == '-' || av[i][j] == '+')
		arg[k++] = av[i][j++];
	while (av[i][j])
	{
		if (!ft_isdigit(av[i][j]))
			free_exit(EXIT_INVALID_INPUT, av, ac_changed);
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
		arg[k] = '0';
	return (k);
}

static int	_is_int(char *arg, int k)
{
	int	res;

	if (k <= 2 && (arg[0] == '0' || arg[1] == '0'))
		res = 1;
	else if (k == 1 && (arg[0] == '+' || arg[0] == '-'))
		res = 0;
	else if (k > 11)
		res = 0;
	else if (k == 11 && (ft_isdigit(arg[0])
			|| (arg[0] == '+' && ft_strncmp(arg, "+2147483647", k) > 0)
			|| (arg[0] == '-' && ft_strncmp(arg, "-2147483648", k) > 0)))
		res = 0;
	else if (k == 10 && ft_strncmp(arg, "2147483647", k) > 0)
		res = 0;
	else
		res = 1;
	return (res);
}

