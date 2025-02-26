#include "checker_bonus.h"

static char	***_get_argv(int *ac, char **av);
static int	_parse(char *str, char *arg);
static int	_is_int(char *arg, int len);

char	***handle_input(int *ac, char **av)
{
	int		i;
	int		j;
	int		len;
	char	arg[12];
	char	***argv;

	argv = _get_argv(ac, av);
	i = -1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			ft_bzero(arg, 12);
			len = _parse(argv[i][j++], arg);
			if(len == -1 || !_is_int(arg, len))
				free_exit(EXIT_NOT_INT, argv);
		}
	}
	return (argv);
}

void	handle_occurence(t_stack *a)
{
	t_stack	*ptr;
	t_stack	*ptr_k;

	ptr = a;
	while (ptr)
	{
		ptr_k = ptr->next;
		while (ptr_k)
		{
			if (ptr->nbr == ptr_k->nbr)
			{
				ft_lstclear(&a);
				free_exit(EXIT_OCCURENCE, NULL);
			}
			ptr_k = ptr_k->next;
		}
		ptr = ptr->next;
	}
}

static char	***_get_argv(int *ac, char **av)
{
	char	***argv;
	int		arg_size;
	int		argc;
	int		i;

	argc = 0;
	(*ac)--;
	argv = malloc((*ac + 1) * sizeof(char **));
	if (!argv)
		exit (EXIT_FAILURE);
	argv[*ac] = NULL;
	i = -1;
	while (++i < *ac)
	{
		arg_size = 0;
		argv[i] = ft_split(av[i + 1], &arg_size, ' ');
		if (!argv[i])
			free_exit(EXIT_FAILURE, argv);
		argc += arg_size;
	}
	if (argc == 0)
		free_exit(EXIT_INVALID_INPUT, argv);
	*ac = argc;
	return (argv);
}

static int _parse(char *str, char *arg)
{
	int	k;
	int	len;
	int flag;

	k = 0;
	len = 0;
	flag = 0;
	if (str[k] == '-' || str[k] == '+')
		arg[len++] = str[k++];
	while (str[k])
	{
		if (!ft_isdigit(str[k]))
			return (-1);
		if (!flag && str[k] != '0')
			flag = 1;
		if (flag)
		{
			arg[len++] = str[k];
			if (len > 11)
				break ;
		}
		k++;
	}
	if (!flag && str[k - 1] == '0')
		arg[len] = '0';
	return (len);
}

static int	_is_int(char *arg, int len)
{
	int	ans;

	if (len <= 2 && (arg[0] == '0' || arg[1] == '0'))
		ans = 1;
	else if (len == 1 && (arg[0] == '+' || arg[0] == '-'))
		ans = 0;
	else if (len > 11)
		ans = 0;
	else if (len == 11 && (ft_isdigit(arg[0])
			|| (arg[0] == '+' && ft_strncmp(arg, "+2147483647", len) > 0)
			|| (arg[0] == '-' && ft_strncmp(arg, "-2147483648", len) > 0)))
		ans = 0;
	else if (len == 10 && ft_strncmp(arg, "2147483647", len) > 0)
		ans = 0;
	else
		ans = 1;
	return (ans);
}

