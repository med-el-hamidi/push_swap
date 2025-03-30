#include "checker_bonus.h"

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
			ft_lstadd_back(a, node);
		}
	}
	free_argv(argv);
}

static int	_check_format(char *buffer)
{
	if (!ft_strncmp(buffer, "pa\n", 3)
		|| !ft_strncmp(buffer, "pb\n", 3)
		|| !ft_strncmp(buffer, "sa\n", 3)
		|| !ft_strncmp(buffer, "sb\n", 3)
		|| !ft_strncmp(buffer, "ss\n", 3)
		|| !ft_strncmp(buffer, "ra\n", 3)
		|| !ft_strncmp(buffer, "rra\n", 4)
		|| !ft_strncmp(buffer, "rb\n", 3)
		|| !ft_strncmp(buffer, "rrb\n", 4)
		|| !ft_strncmp(buffer, "rr\n", 3)
		|| !ft_strncmp(buffer, "rrr\n", 4)
		|| buffer[0] == 0)
		return (1);
	return (0);
}

static int	_read(char *buffer)
{
	int		byte;
	int		i;

	i = 0;
	while (i < 4)
	{
		byte = read(0, &buffer[i], 1);
		if (byte < 1 || buffer[i++] == '\n')
			break ;
	}
	return (byte);
}

static void	_checker(t_stack **a)
{
	t_instruct	*ins;
	t_instruct	*node;
	char		buffer[4];
	int			byte;

	ins = NULL;
	byte = 1;
	while (byte > 0)
	{
		ft_bzero(buffer, sizeof(buffer));
		byte = _read(buffer);
		if (byte == -1)
			freelsts_exit(EXIT_FAILURE_READ, a, &ins);
		else if (!_check_format(buffer))
			freelsts_exit(EXIT_WRONG_FORMAT, a, &ins);
		else if (!byte)
			break ;
		node = ft_lstnew_(buffer);
		if (!node || (node && !node->str))
			freelsts_exit(EXIT_FAILURE, a, &ins);
		ft_lstadd_back_(&ins, node);
	}
	output(a, ins);
	freelsts_exit(EXIT_SUCCESS, a, &ins);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	char	***argv;

	if (ac < 2)
		return (EXIT_SUCCESS);
	argv = handle_input(&ac, av);
	a = NULL;
	_fill_stack(&a, argv);
	handle_occurence(a);
	_checker(&a);
	return (EXIT_SUCCESS);
}
